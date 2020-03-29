// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_PULSE_MOTOR_H_
#define V1_PULSE_MOTOR_H_

#include <stdbool.h>

#include "command.h"

typedef struct PulseMotorStruct* PulseMotor;
typedef struct {
  void (*Delete)(PulseMotor* self);
  int (*Id)(PulseMotor self);
  const char* (*Tag)(PulseMotor self);
  const char* (*State)(PulseMotor self);
  bool (*IsOn)(PulseMotor self);
  Command (*PulseMotorOnCommand)(PulseMotor self);
  Command (*PulseMotorOffCommand)(PulseMotor self);
  Command (*PulseMotorForceOffCommand)(PulseMotor self);
  const char* (*GetDirection)(PulseMotor self);
  void (*SetDirection)(PulseMotor self, const char* direction);
  int (*GetSpeed)(PulseMotor self);
  void (*SetSpeed)(PulseMotor self, int rpm);
  Command (*PulseMotorStopCommand)(PulseMotor self, int pulse);
  Command (*PulseMotorWatchCommand)(PulseMotor self, int pulse, Command notification_command);
  const char* (*GetMode)(PulseMotor self);
  void (*SelectMode)(PulseMotor self, const char* mode);
  int (*GetPulseRate)(PulseMotor self);
  void (*SetPulseRate)(PulseMotor self, int pps);
  int (*GetPosition)(PulseMotor self);
} PulseMotorInterfaceStruct;
typedef const PulseMotorInterfaceStruct* PulseMotorInterface;

extern const PulseMotorInterface pulseMotor;

#endif  // V1_PULSE_MOTOR_H_
