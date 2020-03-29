// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SOLENOID_H_
#define V1_SOLENOID_H_

#include <stdbool.h>

#include "command.h"

typedef struct SolenoidStruct* Solenoid;
typedef struct {
  void (*Delete)(Solenoid* self);
  int (*Id)(Solenoid self);
  const char* (*Tag)(Solenoid self);
  const char* (*State)(Solenoid self);
  bool (*IsOn)(Solenoid self);
  Command (*SolenoidOnCommand)(Solenoid self);
  Command (*SolenoidOffCommand)(Solenoid self);
  Command (*SolenoidForceOffCommand)(Solenoid self);
} SolenoidInterfaceStruct;
typedef const SolenoidInterfaceStruct* SolenoidInterface;

extern const SolenoidInterface solenoid;

#endif  // V1_SOLENOID_H_
