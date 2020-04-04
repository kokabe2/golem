// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_NULL_LED_H_
#define V1_NULL_LED_H_

#include "led.h"

typedef struct {
  Component (*GetInstance)(void);  //
} NullLedMethodStruct;
typedef const NullLedMethodStruct* NullLedMethod;

extern const NullLedMethod nullLed;

#endif  // V1_NULL_LED_H_
