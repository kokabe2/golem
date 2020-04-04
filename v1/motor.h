// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_MOTOR_H_
#define V1_MOTOR_H_

#include <stdbool.h>

#include "command.h"
#include "component.h"

typedef struct {
  void (*Delete)(Component* self);
  int (*Id)(Component self);
  const char* (*Tag)(Component self);
  const char* (*State)(Component self);
  bool (*IsOn)(Component self);
  const char* (*GetDirection)(Component self);
  void (*SetDirection)(Component self, const char* direction);
  int (*GetSpeed)(Component self);
  void (*SetSpeed)(Component self, int rpm);
} MotorInterfaceStruct;
typedef const MotorInterfaceStruct* MotorInterface;

extern const MotorInterface motor;

#endif  // V1_MOTOR_H_
