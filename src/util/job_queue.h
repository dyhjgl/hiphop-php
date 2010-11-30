/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010 Facebook, Inc. (http://www.facebook.com)          |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef __CONCURRENCY_JOB_QUEUE_H__
#define __CONCURRENCY_JOB_QUEUE_H__

#include "async_func.h"
#include <vector>
#include "synchronizable_multi.h"
#include "lock.h"
#include "atomic.h"
#include "alloc.h"
#include "exception.h"

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

/**
 * A queue-based multi-threaded job processing facility. Internally, we have a
 * queue of jobs and a list of workers, each of which runs in its own thread.
 * Job queue can take new jobs on the fly and workers will continue to pull
 * jobs off the queue and work on it.
 *
 * To use it, simply define your own job and worker class like this,
 *
 *   class MyJob {
 *     public:
 *       // storing job data
 *   };
 *
 *   class MyWorker : public JobQueueWorker<MyJob*> {
 *     public:
 *       virtual void doJob(MyJob *job) {
 *         // process the job
 *         delete job; // if it was new-ed
 *       }
 *   };
 *
 * Now, use JobQueueDispatcher to start the whole thing,
 *
 *   JobQueueDispatcher<MyJob*, MyWorker> dispatcher(40, NULL); // 40 threads
 *   dispatcher.start();
 *   ...
 *   dispatcher.enqueue(new MyJob(...));
 *   ...
 *   dispatcher.stop();
 *
 * Note this class is different from JobListDispatcher that uses a vector to
 * store prepared jobs. With JobQueueDispatcher, job queue is normally empty
 * initially and new jobs are pushed into the queue over time. Also, workers
 * can be stopped individually.
 */

///////////////////////////////////////////////////////////////////////////////

/**
 * A job queue that's suitable for multiple threads to work on.
 */
template<typename TJob>
class JobQueue : public SynchronizableMulti {
public:
  // trial class for signaling queue stop
  class StopSignal {};

public:
  /**
   * Constructor.
   */
  JobQueue(int threadCount, bool threadRoundRobin, int dropCacheTimeout,
           bool lifo)
      : SynchronizableMulti(threadRoundRobin ? 1 : threadCount),
        m_jobCount(0), m_stopped(false), m_workerCount(0),
        m_dropCacheTimeout(dropCacheTimeout), m_lifo(lifo) {
  }

  /**
   * Put a job into the queue and notify a worker to pick it up.
   */
  void enqueue(TJob job) {
    Lock lock(this);
    m_jobs.push_back(job);
    m_jobCount = m_jobs.size();
    notify();
  }

  /**
   * Grab a job from the queue for processing. Since the job was not created
   * by this queue class, it's up to a worker class on whether to deallocate
   * the job object correctly.
   */
  TJob dequeue(int id) {
    Lock lock(this);
    bool flushed = false;
    while (m_jobs.empty()) {
      if (m_stopped) {
        throw StopSignal();
      }
      if (m_dropCacheTimeout <= 0 || flushed) {
        wait(id, false);
      } else if (!wait(id, true, m_dropCacheTimeout)) {
        // since we timed out, maybe we can turn idle without holding memory
        if (m_jobs.empty()) {
          Util::flush_thread_caches();
          flushed = true;
        }
      }
    }
    m_jobCount = m_jobs.size() - 1;
    if (m_lifo) {
      TJob job = m_jobs.back();
      m_jobs.pop_back();
      return job;
    }
    TJob job = m_jobs.front();
    m_jobs.pop_front();
    return job;
  }

  /**
   * Purely for making sure no new jobs are queued when we are stopping.
   */
  void stop() {
    Lock lock(this);
    m_stopped = true;
    notifyAll(); // so all waiting threads can find out queue is stopped
  }

  /**
   * Keeps track of how many active workers are working on the queue.
   */
  void incActiveWorker() {
    atomic_inc(m_workerCount);
  }
  void decActiveWorker() {
    atomic_dec(m_workerCount);
  }
  int getActiveWorker() {
    return m_workerCount;
  }

  /**
   * Keep track of how many jobs are queued, but not yet been serviced.
   */
  int getQueuedJobs() {
    return m_jobCount;
  }

 private:
  int m_jobCount;
  std::deque<TJob> m_jobs;
  bool m_stopped;
  int m_workerCount;
  int m_dropCacheTimeout;
  bool m_lifo;
};

///////////////////////////////////////////////////////////////////////////////

/**
 * Base class for a customized worker.
 */
template<typename TJob, bool countActive = false>
class JobQueueWorker {
public:
  /**
   * Default constructor.
   */
  JobQueueWorker() : m_opaque(NULL), m_queue(NULL), m_stopped(false) {
  }

  virtual ~JobQueueWorker() {
  }

  /**
   * Two-phase object creation for easier derivation and for JobQueueDispatcher
   * to easily create a vector of workers.
   */
  void create(int id, JobQueue<TJob> *queue, void *opaque) {
    ASSERT(queue);
    m_id = id;
    m_queue = queue;
    m_opaque = opaque;
  }

  /**
   * The only functions a subclass needs to implement.
   */
  virtual void doJob(TJob job) = 0;
  virtual void onThreadEnter() {}
  virtual void onThreadExit() {}

  /**
   * Start this worker thread.
   */
  void start() {
    ASSERT(m_queue);
    onThreadEnter();
    while (!m_stopped) {
      try {
        TJob job = m_queue->dequeue(m_id);
        if (countActive) m_queue->incActiveWorker();
        doJob(job);
        if (countActive) m_queue->decActiveWorker();
      } catch (typename JobQueue<TJob>::StopSignal) {
        m_stopped = true; // queue is empty and stopped, so we are done
      }
    }
    onThreadExit();
  }

  /**
   * Stop this worker thread.
   */
  void stop() {
    m_stopped = true;
  }

protected:
  int m_id;
  void *m_opaque;

private:

  JobQueue<TJob> *m_queue;
  bool m_stopped;
};

///////////////////////////////////////////////////////////////////////////////

/**
 * Driver class to push through the whole thing.
 */
template<typename TJob, class TWorker>
class JobQueueDispatcher {
public:
  /**
   * Constructor.
   */
  JobQueueDispatcher(int threadCount, bool threadRoundRobin,
                     int dropCacheTimeout, void *opaque, bool lifo = false)
      : m_stopped(true),
        m_queue(threadCount, threadRoundRobin, dropCacheTimeout, lifo) {
    ASSERT(threadCount >= 1);
    m_workers.resize(threadCount);
    m_funcs.resize(threadCount);
    for (int i = 0; i < threadCount; i++) {
      TWorker &worker = m_workers[i];
      worker.create(i, &m_queue, opaque);
      m_funcs[i] = new AsyncFunc<TWorker>(&worker, &TWorker::start);
    }
  }

  ~JobQueueDispatcher() {
    stop();
    for (unsigned int i = 0; i < m_funcs.size(); i++) {
      delete m_funcs[i];
    }
  }

  std::vector<TWorker> &getWorkers() {
    return m_workers;
  }
  int getActiveWorker() {
    return m_queue.getActiveWorker();
  }
  int getQueuedJobs() {
    return m_queue.getQueuedJobs();
  }

  /**
   * Creates worker threads and start running them. This is non-blocking.
   */
  void start() {
    for (unsigned int i = 0; i < m_funcs.size(); i++) {
      m_funcs[i]->start();
    }
    m_stopped = false;
  }

  /**
   * Enqueue a new job.
   */
  void enqueue(TJob job) {
    m_queue.enqueue(job);
  }

  /**
   * Stop all workers after all jobs are processed. No new jobs should be
   * enqueued at this moment, or this call may block for longer time.
   */
  void stop() {
    if (m_stopped) return;
    m_stopped = true;

    m_queue.stop();
    bool exceptioned = false;
    Exception exception;
    for (unsigned int i = 0; i < m_funcs.size(); i++) {
      try {
        m_funcs[i]->waitForEnd();
      } catch (Exception &e) {
        exceptioned = true;
        exception = e;
      }
    }
    if (exceptioned) {
      throw exception;
    }
  }

  void run() {
    start();
    stop();
  }

private:
  bool m_stopped;
  JobQueue<TJob> m_queue;
  std::vector<TWorker> m_workers;
  std::vector<AsyncFunc<TWorker> *> m_funcs;
};

///////////////////////////////////////////////////////////////////////////////
}

#endif // __CONCURRENCY_JOB_QUEUE_H__
