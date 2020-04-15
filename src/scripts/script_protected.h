// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef SRC_SCRIPTS_SCRIPT_PROTECTED_H_
#define SRC_SCRIPTS_SCRIPT_PROTECTED_H_

#include "script.h"

typedef struct ScriptStruct {
  CommandInterfaceStruct impl;
  ActiveObjectEngine engine;
  Command notification_command;
  const char* name;
  int error_code;
} ScriptStruct;

#endif  // SRC_SCRIPTS_SCRIPT_PROTECTED_H_
