// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SCRIPT_RUNNER_H_
#define V1_SCRIPT_RUNNER_H_

#include "script.h"

typedef struct {
  Script (*New)(void);
  void (*AddScript)(Script self, Script script);
} ScriptRunnerMethodStruct;
typedef const ScriptRunnerMethodStruct* ScriptRunnerMethod;

extern const ScriptRunnerMethod scriptRunner;

#endif  // V1_SCRIPT_RUNNER_H_
