// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef SRC_SCRIPTS_COMMAND_SCRIPT_HANDLE_SPY_H_
#define SRC_SCRIPTS_COMMAND_SCRIPT_HANDLE_SPY_H_

#include "command_script_handle.h"

typedef struct {
  CommandScriptHandle (*New)(void);
  void (*Delete)(CommandScriptHandle* self);
  bool (*DeleteCalled)(CommandScriptHandle self);
  void (*NoNeedToExecute)(CommandScriptHandle self);
  void (*SetPreconditionError)(CommandScriptHandle self, int error_code);
  bool (*InitCalled)(CommandScriptHandle self);
  void (*SetCountToDone)(CommandScriptHandle self, int count);
  int (*IdleCalledCount)(CommandScriptHandle self);
  void (*SetPostconditionError)(CommandScriptHandle self, int error_code);
  bool (*CleanUpCalled)(CommandScriptHandle self);
} CommandScriptHandleSpyMethodStruct;
typedef const CommandScriptHandleSpyMethodStruct* CommandScriptHandleSpyMethod;

extern const CommandScriptHandleSpyMethod commandScriptHandleSpy;

#endif  // SRC_SCRIPTS_COMMAND_SCRIPT_HANDLE_SPY_H_
