// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_LED_ARRAY_PRIVATE_H_
#define V1_LED_ARRAY_PRIVATE_H_

#include "led_array.h"

typedef struct LedArrayStruct {
  LedArrayInterface impl;
  int id;
  const char *tag;
} LedArrayStruct;

#endif  // V1_LED_ARRAY_PRIVATE_H_
