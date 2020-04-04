// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_NULL_MOTOR_H_
#define V1_NULL_MOTOR_H_

#include "motor.h"

typedef struct {
  Component (*GetInstance)(void);  //
} NullMotorMethodStruct;
typedef const NullMotorMethodStruct* NullMotorMethod;

extern const NullMotorMethod nullMotor;

#endif  // V1_NULL_MOTOR_H_
