// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef SRC_SCRIPTS_SCRIPT_SPY_H_
#define SRC_SCRIPTS_SCRIPT_SPY_H_

#include "script.h"

typedef struct {
  Script (*New)(const char* name);
  void (*Delete)(Script* self);
  bool (*DeleteCalled)(Script self);
  bool (*RunCalled)(Script self);
  ActiveObjectEngine (*GetEngine)(Script self);
  Command (*GetNotificationCommand)(Script self);
  void (*SetErrorCode)(Script self, int error_code);
} ScriptSpyMethodStruct;
typedef const ScriptSpyMethodStruct* ScriptSpyMethod;

extern const ScriptSpyMethod scriptSpy;

#endif  // SRC_SCRIPTS_SCRIPT_SPY_H_
