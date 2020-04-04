// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_PULSE_MOTOR_H_
#define V1_PULSE_MOTOR_H_

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
  const char* (*GetMode)(Component self);
  void (*SelectMode)(Component self, const char* mode);
  int (*GetPulseRate)(Component self);
  void (*SetPulseRate)(Component self, int pps);
  int (*GetPosition)(Component self);
} PulseMotorInterfaceStruct;
typedef const PulseMotorInterfaceStruct* PulseMotorInterface;

extern const PulseMotorInterface pulseMotor;

#endif  // V1_PULSE_MOTOR_H_
