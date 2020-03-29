// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_MOTOR_PRIVATE_H_
#define V1_MOTOR_PRIVATE_H_

#include "motor.h"

typedef struct MotorStruct {
  MotorInterface impl;
  int id;
  const char *tag;
} MotorStruct;

#endif  // V1_MOTOR_PRIVATE_H_
