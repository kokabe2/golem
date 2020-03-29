// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_ACTUATOR_H_
#define V1_ACTUATOR_H_

#include <stdbool.h>

#include "command.h"

typedef struct ActuatorStruct* Actuator;
typedef struct {
  void (*Delete)(Actuator* self);
  int (*Id)(Actuator self);
  const char* (*Tag)(Actuator self);
  const char* (*State)(Actuator self);
  bool (*IsOn)(Actuator self);
  Command (*ActuatorOnCommand)(Actuator self);
  Command (*ActuatorOffCommand)(Actuator self);
  Command (*ActuatorForceOffCommand)(Actuator self);
} ActuatorInterfaceStruct;
typedef const ActuatorInterfaceStruct* ActuatorInterface;

extern const ActuatorInterface actuator;

#endif  // V1_ACTUATOR_H_
