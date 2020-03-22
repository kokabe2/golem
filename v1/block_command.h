// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_BLOCK_COMMAND_H_
#define V1_BLOCK_COMMAND_H_

#include "command.h"

typedef struct {
  Command (*New)(int microseconds);  //
} BlockCommandMethodStruct;
typedef const BlockCommandMethodStruct* BlockCommandMethod;

extern const BlockCommandMethod blockCommand;

#endif  // V1_BLOCK_COMMAND_H_
