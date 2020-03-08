// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_LED_ARRAY_INTERFACE_H_
#define V1_LED_ARRAY_INTERFACE_H_

#include <stdbool.h>

typedef struct {
  int (*Id)(void);
  const char* (*Tag)(void);
  void (*TurnAllOff)(void);
  void (*TurnAllOn)(void);
  bool (*IsAllOff)(void);
  bool (*IsAllOn)(void);
  void (*TurnOff)(int led_id);
  void (*TurnOn)(int led_id);
  bool (*IsOff)(int led_id);
  bool (*IsOn)(int led_id);
} LedArrayInterfaceStruct;
typedef const LedArrayInterfaceStruct* LedArrayInterface;

#endif  // V1_LED_ARRAY_INTERFACE_H_
