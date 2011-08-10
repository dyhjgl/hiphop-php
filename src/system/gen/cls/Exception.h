/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010- Facebook, Inc. (http://www.facebook.com)         |
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
// @generated by HipHop Compiler

#ifndef __GENERATED_cls_Exception_h22b3de5c__
#define __GENERATED_cls_Exception_h22b3de5c__

#include <cls/Exception.fw.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

/* SRC: classes/exception.php line 10 */
FORWARD_DECLARE_CLASS(Exception);
extern const ObjectStaticCallbacks cw_Exception;
class c_Exception : public ExtObjectData {
  public:

  // Properties
  Variant m_message;
  Variant m_code;
  Variant m_previous;
  Variant m_file;
  Variant m_line;
  Variant m_trace;

  // Class Map
  DECLARE_CLASS_COMMON_NO_SWEEP(Exception, Exception)

  // DECLARE_STATIC_PROP_OPS
  public:
  static Variant os_getInit(CStrRef s);
  #define OMIT_JUMP_TABLE_CLASS_STATIC_GET_Exception 1
  #define OMIT_JUMP_TABLE_CLASS_STATIC_LVAL_Exception 1
  #define OMIT_JUMP_TABLE_CLASS_CONSTANT_Exception 1

  // DECLARE_COMMON_INVOKE
  static const MethodCallInfoTable s_call_info_table[];
  static const int s_call_info_index[];

  public:
  static const ClassPropTable os_prop_table;
  c_Exception() : m_previous(Variant::nullInit), m_file(Variant::nullInit), m_line(Variant::nullInit), m_trace(Variant::nullInit) {}
  void init();
  public: void t___init__();
  public: void t___construct(Variant v_message = NAMSTR(s_sys_ss00000000, ""), Variant v_code = 0LL, Variant v_previous = null);
  public: c_Exception *create(CVarRef v_message = NAMVAR(s_sys_svs00000000, ""), CVarRef v_code = NAMVAR(s_sys_svif01bca90, 0LL), CVarRef v_previous = null_variant);
  public: void dynConstruct(CArrRef params);
  public: void getConstructor(MethodCallPackage &mcp);
  public: Variant t_getmessage();
  public: Variant t_getprevious();
  public: Variant t_getcode();
  public: Variant t_getfile();
  public: Variant t_getline();
  public: Variant t_gettrace();
  public: String t_gettraceasstring();
  public: String t___tostring();
  DECLARE_METHOD_INVOKE_HELPERS(getmessage);
  DECLARE_METHOD_INVOKE_HELPERS(__tostring);
  DECLARE_METHOD_INVOKE_HELPERS(__construct);
  DECLARE_METHOD_INVOKE_HELPERS(getcode);
  DECLARE_METHOD_INVOKE_HELPERS(getprevious);
  DECLARE_METHOD_INVOKE_HELPERS(getline);
  DECLARE_METHOD_INVOKE_HELPERS(__init__);
  DECLARE_METHOD_INVOKE_HELPERS(getfile);
  DECLARE_METHOD_INVOKE_HELPERS(gettraceasstring);
  DECLARE_METHOD_INVOKE_HELPERS(gettrace);
};
ObjectData *coo_Exception() NEVER_INLINE;

///////////////////////////////////////////////////////////////////////////////
}

#endif // __GENERATED_cls_Exception_h22b3de5c__
