// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_PULSE_MOTOR_H_
#define V1_PULSE_MOTOR_H_

#include "motor.h"

typedef struct PulseMotorInterfaceStruct* PulseMotor;
typedef struct PulseMotorInterfaceStruct {
  void (*Delete)(PulseMotor* self);
  int (*Id)(PulseMotor self);
  const char* (*Tag)(PulseMotor self);
  const char* (*State)(PulseMotor self);
  bool (*IsStopped)(PulseMotor self);
  void (*Run)(PulseMotor self);
  void (*Stop)(PulseMotor self);
  void (*ForceStop)(PulseMotor self);
  const char* (*GetDirection)(PulseMotor self);
  void (*SetDirection)(PulseMotor self, const char* direction);
  int (*GetSpeed)(PulseMotor self);
  void (*SetSpeed)(PulseMotor self, int rpm);
  const char* (*GetMode)(PulseMotor self);
  void (*SelectMode)(PulseMotor self, const char* mode);
  int (*GetPulseRate)(PulseMotor self);
  void (*SetPulseRate)(PulseMotor self, int pps);
  int (*GetPosition)(PulseMotor self);
} PulseMotorInterfaceStruct;

#endif  // V1_PULSE_MOTOR_H_
