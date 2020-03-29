// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_MOTOR_H_
#define V1_MOTOR_H_

#include <stdbool.h>

#include "command.h"

typedef struct MotorStruct* Motor;
typedef struct {
  void (*Delete)(Motor* self);
  int (*Id)(Motor self);
  const char* (*Tag)(Motor self);
  const char* (*State)(Motor self);
  bool (*IsOn)(Motor self);
  Command (*MotorOnCommand)(Motor self);
  Command (*MotorOffCommand)(Motor self);
  Command (*MotorForceOffCommand)(Motor self);
  const char* (*GetDirection)(Motor self);
  void (*SetDirection)(Motor self, const char* direction);
  int (*GetSpeed)(Motor self);
  void (*SetSpeed)(Motor self, int rpm);
} MotorInterfaceStruct;
typedef const MotorInterfaceStruct* MotorInterface;

extern const MotorInterface motor;

#endif  // V1_MOTOR_H_
