/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010 Facebook, Inc. (http://www.facebook.com)          |
   | Copyright (c) 1997-2010 The PHP Group                                |
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

#ifndef __EXTPROFILE_BZIP2_H__
#define __EXTPROFILE_BZIP2_H__

// >>>>>> Generated by idl.php. Do NOT modify. <<<<<<

#include <runtime/ext/ext_bzip2.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

inline Variant x_bzclose(CObjRef bz) {
  FUNCTION_INJECTION_BUILTIN(bzclose);
  return f_bzclose(bz);
}

inline Variant x_bzopen(CStrRef filename, CStrRef mode) {
  FUNCTION_INJECTION_BUILTIN(bzopen);
  return f_bzopen(filename, mode);
}

inline Variant x_bzread(CObjRef bz, int length = 1024) {
  FUNCTION_INJECTION_BUILTIN(bzread);
  return f_bzread(bz, length);
}

inline Variant x_bzwrite(CObjRef bz, CStrRef data, int length = 0) {
  FUNCTION_INJECTION_BUILTIN(bzwrite);
  return f_bzwrite(bz, data, length);
}

inline Variant x_bzflush(CObjRef bz) {
  FUNCTION_INJECTION_BUILTIN(bzflush);
  return f_bzflush(bz);
}

inline String x_bzerrstr(CObjRef bz) {
  FUNCTION_INJECTION_BUILTIN(bzerrstr);
  return f_bzerrstr(bz);
}

inline Variant x_bzerror(CObjRef bz) {
  FUNCTION_INJECTION_BUILTIN(bzerror);
  return f_bzerror(bz);
}

inline int x_bzerrno(CObjRef bz) {
  FUNCTION_INJECTION_BUILTIN(bzerrno);
  return f_bzerrno(bz);
}

inline Variant x_bzcompress(CStrRef source, int blocksize = 4, int workfactor = 0) {
  FUNCTION_INJECTION_BUILTIN(bzcompress);
  return f_bzcompress(source, blocksize, workfactor);
}

inline Variant x_bzdecompress(CStrRef source, int small = 0) {
  FUNCTION_INJECTION_BUILTIN(bzdecompress);
  return f_bzdecompress(source, small);
}


///////////////////////////////////////////////////////////////////////////////
}

#endif // __EXTPROFILE_BZIP2_H__
