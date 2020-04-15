// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SCRIPT_PROTECTED_H_
#define V1_SCRIPT_PROTECTED_H_

#include "script.h"

typedef struct ScriptStruct {
  CommandInterfaceStruct impl;
  ActiveObjectEngine engine;
  Command notification_command;
  const char* name;
  int error_code;
} ScriptStruct;

#endif  // V1_SCRIPT_PROTECTED_H_
