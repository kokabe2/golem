// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_MICROSWITCH_H_
#define V1_MICROSWITCH_H_

#include <stdbool.h>

#include "component.h"

typedef struct {
  void (*Delete)(Component* self);
  int (*Id)(Component self);
  const char* (*Tag)(Component self);
  const char* (*State)(Component self);
  bool (*IsOff)(Component self);
  bool (*IsOn)(Component self);
} MicroswitchInterfaceStruct;
typedef const MicroswitchInterfaceStruct* MicroswitchInterface;

extern const MicroswitchInterface microswitch;

#endif  // V1_MICROSWITCH_H_
