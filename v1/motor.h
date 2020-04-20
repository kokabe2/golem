// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_MOTOR_H_
#define V1_MOTOR_H_

#include "actuator.h"

typedef struct MotorInterfaceStruct* Motor;
typedef struct MotorInterfaceStruct {
  void (*Delete)(Motor* self);
  int (*Id)(Motor self);
  const char* (*Tag)(Motor self);
  const char* (*State)(Motor self);
  bool (*IsStopped)(Motor self);
  void (*Run)(Motor self);
  void (*Stop)(Motor self);
  void (*ForceStop)(Motor self);
  const char* (*GetDirection)(Motor self);
  void (*SetDirection)(Motor self, const char* direction);
  int (*GetSpeed)(Motor self);
  void (*SetSpeed)(Motor self, int rpm);
} MotorInterfaceStruct;

#endif  // V1_MOTOR_H_
