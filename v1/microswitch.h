// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_MICROSWITCH_H_
#define V1_MICROSWITCH_H_

#include <stdbool.h>

#include "command.h"

typedef struct MicroswitchStruct* Microswitch;
typedef struct {
  void (*Delete)(Microswitch* self);
  int (*Id)(Microswitch self);
  const char* (*Tag)(Microswitch self);
  Command (*SensorWatchCommand)(Microswitch self, const char* expected_state, Command notification_command);
  const char* (*State)(Microswitch self);
  bool (*IsOff)(Microswitch self);
  bool (*IsOn)(Microswitch self);
} MicroswitchInterfaceStruct;
typedef const MicroswitchInterfaceStruct* MicroswitchInterface;

extern const MicroswitchInterface microswitch;

#endif  // V1_MICROSWITCH_H_
