// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_ACTUATOR_H_
#define V1_ACTUATOR_H_

#include <stdbool.h>

#include "command.h"
#include "component.h"

typedef struct {
  void (*Delete)(Component* self);
  int (*Id)(Component self);
  const char* (*Tag)(Component self);
  const char* (*State)(Component self);
  bool (*IsOff)(Component self);
  void (*TurnOn)(Component self);
  void (*TurnOff)(Component self);
  void (*ForceTurnOff)(Component self);
} ActuatorInterfaceStruct;
typedef const ActuatorInterfaceStruct* ActuatorInterface;

extern const ActuatorInterface actuator;

#endif  // V1_ACTUATOR_H_
