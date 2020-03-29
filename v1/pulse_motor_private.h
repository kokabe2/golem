// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_PULSE_MOTOR_PRIVATE_H_
#define V1_PULSE_MOTOR_PRIVATE_H_

#include "pulse_motor.h"

typedef struct PulseMotorStruct {
  PulseMotorInterface impl;
  int id;
  const char *tag;
} PulseMotorStruct;

#endif  // V1_PULSE_MOTOR_PRIVATE_H_
