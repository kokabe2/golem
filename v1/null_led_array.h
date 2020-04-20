// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_NULL_LED_ARRAY_H_
#define V1_NULL_LED_ARRAY_H_

#include "led_array.h"

typedef struct {
  LedArray (*GetInstance)(void);  //
} NullLedArrayMethodStruct;
typedef const NullLedArrayMethodStruct* NullLedArrayMethod;

extern const NullLedArrayMethod nullLedArray;

#endif  // V1_NULL_LED_ARRAY_H_
