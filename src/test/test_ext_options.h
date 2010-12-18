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

#ifndef __TEST_EXT_OPTIONS_H__
#define __TEST_EXT_OPTIONS_H__

// >>>>>> Generated by idl.php. Do NOT modify. <<<<<<

#include <test/test_cpp_ext.h>

///////////////////////////////////////////////////////////////////////////////

class TestExtOptions : public TestCppExt {
 public:
  virtual bool RunTests(const std::string &which);

  bool test_assert_options();
  bool test_assert();
  bool test_dl();
  bool test_extension_loaded();
  bool test_get_loaded_extensions();
  bool test_get_extension_funcs();
  bool test_get_cfg_var();
  bool test_get_current_user();
  bool test_get_defined_constants();
  bool test_get_include_path();
  bool test_restore_include_path();
  bool test_set_include_path();
  bool test_get_included_files();
  bool test_inclued_get_data();
  bool test_get_magic_quotes_gpc();
  bool test_get_magic_quotes_runtime();
  bool test_get_required_files();
  bool test_getenv();
  bool test_getlastmod();
  bool test_getmygid();
  bool test_getmyinode();
  bool test_getmypid();
  bool test_getmyuid();
  bool test_getopt();
  bool test_getrusage();
  bool test_clock_getres();
  bool test_clock_gettime();
  bool test_clock_settime();
  bool test_cpu_get_count();
  bool test_cpu_get_model();
  bool test_ini_alter();
  bool test_ini_get_all();
  bool test_ini_get();
  bool test_ini_restore();
  bool test_ini_set();
  bool test_memory_get_peak_usage();
  bool test_memory_get_usage();
  bool test_php_ini_scanned_files();
  bool test_php_logo_guid();
  bool test_php_sapi_name();
  bool test_php_uname();
  bool test_phpcredits();
  bool test_phpinfo();
  bool test_phpversion();
  bool test_putenv();
  bool test_set_magic_quotes_runtime();
  bool test_set_time_limit();
  bool test_sys_get_temp_dir();
  bool test_version_compare();
  bool test_zend_logo_guid();
  bool test_zend_thread_id();
  bool test_zend_version();
};

///////////////////////////////////////////////////////////////////////////////

#endif // __TEST_EXT_OPTIONS_H__
