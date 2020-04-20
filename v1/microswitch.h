// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_MICROSWITCH_H_
#define V1_MICROSWITCH_H_

#include "sensor.h"

typedef struct MicroswitchInterfaceStruct* Microswitch;
typedef struct MicroswitchInterfaceStruct {
  void (*Delete)(Microswitch* self);
  int (*Id)(Microswitch self);
  const char* (*Tag)(Microswitch self);
  const char* (*State)(Microswitch self);
  bool (*IsOff)(Microswitch self);
  bool (*IsOn)(Microswitch self);
} MicroswitchInterfaceStruct;

#endif  // V1_MICROSWITCH_H_
