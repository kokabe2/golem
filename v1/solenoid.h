// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SOLENOID_H_
#define V1_SOLENOID_H_

#include <stdbool.h>

#include "command.h"
#include "component.h"

typedef struct {
  void (*Delete)(Component* self);
  int (*Id)(Component self);
  const char* (*Tag)(Component self);
  const char* (*State)(Component self);
  bool (*IsOn)(Component self);
} SolenoidInterfaceStruct;
typedef const SolenoidInterfaceStruct* SolenoidInterface;

extern const SolenoidInterface solenoid;

#endif  // V1_SOLENOID_H_
