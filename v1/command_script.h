// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_COMMAND_SCRIPT_H_
#define V1_COMMAND_SCRIPT_H_

#include "command_script_handle.h"
#include "script.h"

typedef struct {
  Script (*New)(const char *name, CommandScriptHandle handle);  //
} CommandScriptMethodStruct;
typedef const CommandScriptMethodStruct *CommandScriptMethod;

extern const CommandScriptMethod commandScript;

#endif  // V1_COMMAND_SCRIPT_H_
