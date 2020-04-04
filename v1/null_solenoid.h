// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_NULL_SOLENOID_H_
#define V1_NULL_SOLENOID_H_

#include "solenoid.h"

typedef struct {
  Component (*GetInstance)(void);  //
} NullSolenoidMethodStruct;
typedef const NullSolenoidMethodStruct* NullSolenoidMethod;

extern const NullSolenoidMethod nullSolenoid;

#endif  // V1_NULL_SOLENOID_H_
