// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_LED_H_
#define V1_LED_H_

#include <stdbool.h>

#include "component.h"

typedef struct {
  void (*Delete)(Component* self);
  int (*Id)(Component self);
  const char* (*Tag)(Component self);
  void (*TurnOff)(Component self);
  void (*TurnOn)(Component self);
  bool (*IsOff)(Component self);
  bool (*IsOn)(Component self);
} LedInterfaceStruct;
typedef const LedInterfaceStruct* LedInterface;

extern const LedInterface led;

#endif  // V1_LED_H_
