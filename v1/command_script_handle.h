// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_COMMAND_SCRIPT_HANDLE_H_
#define V1_COMMAND_SCRIPT_HANDLE_H_

#include <stdbool.h>

typedef struct CommandScriptHandleInterfaceStruct* CommandScriptHandle;
typedef struct CommandScriptHandleInterfaceStruct {
  void (*Delete)(CommandScriptHandle* self);
  bool (*NeedsExecute)(CommandScriptHandle self);
  bool (*AssertPrecondition)(CommandScriptHandle self);
  void (*Init)(CommandScriptHandle self);
  bool (*Done)(CommandScriptHandle self);
  void (*Idle)(CommandScriptHandle self);
  bool (*AssertPostcondition)(CommandScriptHandle self);
  void (*CleanUp)(CommandScriptHandle self);
  int (*GetErrorCode)(CommandScriptHandle self);
} CommandScriptHandleInterfaceStruct;
typedef const CommandScriptHandleInterfaceStruct* CommandScriptHandleInterface;

extern const CommandScriptHandleInterface commandScriptHandle;

#endif  // V1_COMMAND_SCRIPT_HANDLE_H_
