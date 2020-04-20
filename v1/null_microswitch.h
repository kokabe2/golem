// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_NULL_MICROSWITCH_H_
#define V1_NULL_MICROSWITCH_H_

#include "microswitch.h"

typedef struct {
  Microswitch (*GetInstance)(void);  //
} NullMicroswitchMethodStruct;
typedef const NullMicroswitchMethodStruct* NullMicroswitchMethod;

extern const NullMicroswitchMethod nullMicroswitch;

#endif  // V1_NULL_MICROSWITCH_H_
