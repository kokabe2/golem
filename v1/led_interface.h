// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_LED_INTERFACE_H_
#define V1_LED_INTERFACE_H_

#include <stdbool.h>

typedef struct {
  int (*Id)(void);
  const char* (*Tag)(void);
  void (*TurnOff)(void);
  void (*TurnOn)(void);
  bool (*IsOff)(void);
  bool (*IsOn)(void);
} LedInterfaceStruct;
typedef const LedInterfaceStruct* LedInterface;

#endif  // V1_LED_INTERFACE_H_
