// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_NULL_DISPLAY_H_
#define V1_NULL_DISPLAY_H_

#include "display.h"

typedef struct {
  Component (*GetInstance)(void);  //
} NullDisplayMethodStruct;
typedef const NullDisplayMethodStruct* NullDisplayMethod;

extern const NullDisplayMethod nullDisplay;

#endif  // V1_NULL_DISPLAY_H_
