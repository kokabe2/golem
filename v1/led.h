﻿// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_LED_H_
#define V1_LED_H_

#include <stdbool.h>

#include "display.h"

typedef struct LedInterfaceStruct* Led;
typedef struct LedInterfaceStruct {
  void (*Delete)(Led* self);
  int (*Id)(Led self);
  const char* (*Tag)(Led self);
  void (*TurnOff)(Led self);
  void (*TurnOn)(Led self);
  bool (*IsOff)(Led self);
  bool (*IsOn)(Led self);
} LedInterfaceStruct;

#endif  // V1_LED_H_
