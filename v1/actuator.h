// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_ACTUATOR_H_
#define V1_ACTUATOR_H_

#include <stdbool.h>

#include "component.h"

typedef struct ActuatorInterfaceStruct* Actuator;
typedef struct ActuatorInterfaceStruct {
  void (*Delete)(Actuator* self);
  int (*Id)(Actuator self);
  const char* (*Tag)(Actuator self);
  const char* (*State)(Actuator self);
  bool (*IsOff)(Actuator self);
  void (*TurnOn)(Actuator self);
  void (*TurnOff)(Actuator self);
  void (*ForceTurnOff)(Actuator self);
} ActuatorInterfaceStruct;

#endif  // V1_ACTUATOR_H_
