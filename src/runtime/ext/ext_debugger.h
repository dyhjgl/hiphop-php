/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010- Facebook, Inc. (http://www.facebook.com)         |
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

#ifndef __EXT_DEBUGGER_H__
#define __EXT_DEBUGGER_H__

// >>>>>> Generated by idl.php. Do NOT modify. <<<<<<

#include <runtime/base/base_includes.h>
#include <runtime/eval/debugger/debugger_client.h>
#include <runtime/eval/debugger/debugger_proxy.h>
namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

bool f_hphpd_install_user_command(CStrRef cmd, CStrRef clsname);
Array f_hphpd_get_user_commands();
void f_hphpd_break(bool condition = true);

///////////////////////////////////////////////////////////////////////////////
// class DebuggerProxy

FORWARD_DECLARE_CLASS_BUILTIN(DebuggerProxy);
class c_DebuggerProxy : public ExtObjectData {
 public:
  DECLARE_CLASS(DebuggerProxy, DebuggerProxy, ObjectData)

  // need to implement
  public: c_DebuggerProxy();
  public: ~c_DebuggerProxy();
  public: void t___construct();
  DECLARE_METHOD_INVOKE_HELPERS(__construct);
  public: bool t_islocal();
  DECLARE_METHOD_INVOKE_HELPERS(islocal);
  public: Variant t_send(CObjRef cmd);
  DECLARE_METHOD_INVOKE_HELPERS(send);
  public: Variant t___destruct();
  DECLARE_METHOD_INVOKE_HELPERS(__destruct);

  // implemented by HPHP
  public: c_DebuggerProxy *create();
  public: void dynConstruct(CArrRef Params);
  public: void getConstructor(MethodCallPackage &mcp);


 public:
  Eval::DebuggerProxy *m_proxy;
};
extern const int64 q_DebuggerClient_AUTO_COMPLETE_FILENAMES;
extern const int64 q_DebuggerClient_AUTO_COMPLETE_VARIABLES;
extern const int64 q_DebuggerClient_AUTO_COMPLETE_CONSTANTS;
extern const int64 q_DebuggerClient_AUTO_COMPLETE_CLASSES;
extern const int64 q_DebuggerClient_AUTO_COMPLETE_FUNCTIONS;
extern const int64 q_DebuggerClient_AUTO_COMPLETE_CLASS_METHODS;
extern const int64 q_DebuggerClient_AUTO_COMPLETE_CLASS_PROPERTIES;
extern const int64 q_DebuggerClient_AUTO_COMPLETE_CLASS_CONSTANTS;
extern const int64 q_DebuggerClient_AUTO_COMPLETE_KEYWORDS;
extern const int64 q_DebuggerClient_AUTO_COMPLETE_CODE;

///////////////////////////////////////////////////////////////////////////////
// class DebuggerClient

FORWARD_DECLARE_CLASS_BUILTIN(DebuggerClient);
class c_DebuggerClient : public ExtObjectData {
 public:
  DECLARE_CLASS(DebuggerClient, DebuggerClient, ObjectData)

  // need to implement
  public: c_DebuggerClient();
  public: ~c_DebuggerClient();
  public: void t___construct();
  DECLARE_METHOD_INVOKE_HELPERS(__construct);
  public: void t_quit();
  DECLARE_METHOD_INVOKE_HELPERS(quit);
  public: void t_print(int _argc, CStrRef format, CArrRef _argv = null_array);
  DECLARE_METHOD_INVOKE_HELPERS(print);
  public: void t_help(int _argc, CStrRef format, CArrRef _argv = null_array);
  DECLARE_METHOD_INVOKE_HELPERS(help);
  public: void t_info(int _argc, CStrRef format, CArrRef _argv = null_array);
  DECLARE_METHOD_INVOKE_HELPERS(info);
  public: void t_output(int _argc, CStrRef format, CArrRef _argv = null_array);
  DECLARE_METHOD_INVOKE_HELPERS(output);
  public: void t_error(int _argc, CStrRef format, CArrRef _argv = null_array);
  DECLARE_METHOD_INVOKE_HELPERS(error);
  public: void t_code(CStrRef source, int highlight_line = 0, int start_line_no = 0, int end_line_no = 0);
  DECLARE_METHOD_INVOKE_HELPERS(code);
  public: Variant t_ask(int _argc, CStrRef format, CArrRef _argv = null_array);
  DECLARE_METHOD_INVOKE_HELPERS(ask);
  public: String t_wrap(CStrRef str);
  DECLARE_METHOD_INVOKE_HELPERS(wrap);
  public: void t_helptitle(CStrRef str);
  DECLARE_METHOD_INVOKE_HELPERS(helptitle);
  public: void t_helpcmds(int _argc, CStrRef cmd, CStrRef desc, CArrRef _argv = null_array);
  DECLARE_METHOD_INVOKE_HELPERS(helpcmds);
  public: void t_helpbody(CStrRef str);
  DECLARE_METHOD_INVOKE_HELPERS(helpbody);
  public: void t_helpsection(CStrRef str);
  DECLARE_METHOD_INVOKE_HELPERS(helpsection);
  public: void t_tutorial(CStrRef str);
  DECLARE_METHOD_INVOKE_HELPERS(tutorial);
  public: String t_getcode();
  DECLARE_METHOD_INVOKE_HELPERS(getcode);
  public: String t_getcommand();
  DECLARE_METHOD_INVOKE_HELPERS(getcommand);
  public: bool t_arg(int index, CStrRef str);
  DECLARE_METHOD_INVOKE_HELPERS(arg);
  public: int t_argcount();
  DECLARE_METHOD_INVOKE_HELPERS(argcount);
  public: String t_argvalue(int index);
  DECLARE_METHOD_INVOKE_HELPERS(argvalue);
  public: String t_argrest(int index);
  DECLARE_METHOD_INVOKE_HELPERS(argrest);
  public: Array t_args();
  DECLARE_METHOD_INVOKE_HELPERS(args);
  public: Variant t_send(CObjRef cmd);
  DECLARE_METHOD_INVOKE_HELPERS(send);
  public: Variant t_xend(CObjRef cmd);
  DECLARE_METHOD_INVOKE_HELPERS(xend);
  public: Variant t_getcurrentlocation();
  DECLARE_METHOD_INVOKE_HELPERS(getcurrentlocation);
  public: Variant t_getstacktrace();
  DECLARE_METHOD_INVOKE_HELPERS(getstacktrace);
  public: int t_getframe();
  DECLARE_METHOD_INVOKE_HELPERS(getframe);
  public: void t_printframe(int index);
  DECLARE_METHOD_INVOKE_HELPERS(printframe);
  public: void t_addcompletion(CVarRef list);
  DECLARE_METHOD_INVOKE_HELPERS(addcompletion);
  public: Variant t___destruct();
  DECLARE_METHOD_INVOKE_HELPERS(__destruct);

  // implemented by HPHP
  public: c_DebuggerClient *create();
  public: void dynConstruct(CArrRef Params);
  public: void getConstructor(MethodCallPackage &mcp);


 public:
  Eval::DebuggerClient *m_client;
};

///////////////////////////////////////////////////////////////////////////////
}

#endif // __EXT_DEBUGGER_H__
