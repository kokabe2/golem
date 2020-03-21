// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef SRC_UTIL_COMMAND_PROTECTED_H_
#define SRC_UTIL_COMMAND_PROTECTED_H_

#include "command.h"

typedef struct CommandStruct {
  CommandAbstractMethod impl;  //
} CommandStruct;

#endif  // SRC_UTIL_COMMAND_PROTECTED_H_
