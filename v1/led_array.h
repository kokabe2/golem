// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_LED_ARRAY_H_
#define V1_LED_ARRAY_H_

#include <stdbool.h>

#include "component.h"

typedef struct {
  void (*Delete)(Component* self);
  int (*Id)(Component self);
  const char* (*Tag)(Component self);
  void (*TurnAllOff)(Component self);
  void (*TurnAllOn)(Component self);
  bool (*IsAllOff)(Component self);
  bool (*IsAllOn)(Component self);
  void (*TurnOff)(Component self, int led_id);
  void (*TurnOn)(Component self, int led_id);
  bool (*IsOff)(Component self, int led_id);
  bool (*IsOn)(Component self, int led_id);
} LedArrayInterfaceStruct;
typedef const LedArrayInterfaceStruct* LedArrayInterface;

extern const LedArrayInterface ledArray;

#endif  // V1_LED_ARRAY_H_
