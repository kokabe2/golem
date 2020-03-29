// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_NULL_ACTUATOR_H_
#define V1_NULL_ACTUATOR_H_

#include "actuator.h"

typedef struct {
  Actuator (*GetInstance)(void);  //
} NullActuatorMethodStruct;
typedef const NullActuatorMethodStruct* NullActuatorMethod;

extern const NullActuatorMethod nullActuator;

#endif  // V1_NULL_ACTUATOR_H_
