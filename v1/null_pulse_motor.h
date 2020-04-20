// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_NULL_PULSE_MOTOR_H_
#define V1_NULL_PULSE_MOTOR_H_

#include "pulse_motor.h"

typedef struct {
  PulseMotor (*GetInstance)(void);  //
} NullPulseMotorMethodStruct;
typedef const NullPulseMotorMethodStruct* NullPulseMotorMethod;

extern const NullPulseMotorMethod nullPulseMotor;

#endif  // V1_NULL_PULSE_MOTOR_H_
