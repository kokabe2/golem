// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_COMMAND_PROTECTED_H_
#define V1_COMMAND_PROTECTED_H_

#include "command.h"

typedef struct CommandStruct {
  CommandAbstractMethod impl;  //
} CommandStruct;

#endif  // V1_COMMAND_PROTECTED_H_
