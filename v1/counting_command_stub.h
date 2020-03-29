// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_COUNTING_COMMAND_STUB_H_
#define V1_COUNTING_COMMAND_STUB_H_

#include "command.h"

typedef struct {
  Command (*New)(void);
  int (*Count)(Command self);
} CountingCommandStubMethodStruct;
typedef const CountingCommandStubMethodStruct* CountingCommandStubMethod;

extern const CountingCommandStubMethod countingCommandStub;

#endif  // V1_COUNTING_COMMAND_STUB_H_
