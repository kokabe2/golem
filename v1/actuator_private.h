// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_ACTUATOR_PRIVATE_H_
#define V1_ACTUATOR_PRIVATE_H_

#include "actuator.h"

typedef struct ActuatorStruct {
  ActuatorInterface impl;
  int id;
  const char *tag;
} ActuatorStruct;

#endif  // V1_ACTUATOR_PRIVATE_H_
