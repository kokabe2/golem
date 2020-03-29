// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_LED_PRIVATE_H_
#define V1_LED_PRIVATE_H_

#include "led.h"

typedef struct LedStruct {
  LedInterface impl;
  int id;
  const char *tag;
} LedStruct;

#endif  // V1_LED_PRIVATE_H_
