// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SOLENOID_PRIVATE_H_
#define V1_SOLENOID_PRIVATE_H_

#include "solenoid.h"

typedef struct SolenoidStruct {
  SolenoidInterface impl;
  int id;
  const char *tag;
} SolenoidStruct;

#endif  // V1_SOLENOID_PRIVATE_H_
