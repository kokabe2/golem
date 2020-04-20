// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SOLENOID_H_
#define V1_SOLENOID_H_

#include "actuator.h"

typedef struct SolenoidInterfaceStruct* Solenoid;
typedef struct SolenoidInterfaceStruct {
  void (*Delete)(Solenoid* self);
  int (*Id)(Solenoid self);
  const char* (*Tag)(Solenoid self);
  const char* (*State)(Solenoid self);
  bool (*IsUnlocked)(Solenoid self);
  void (*Lock)(Solenoid self);
  void (*Unlock)(Solenoid self);
  void (*ForceUnlock)(Solenoid self);
} SolenoidInterfaceStruct;

#endif  // V1_SOLENOID_H_
