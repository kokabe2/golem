// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_ACTUATOR_FACTORY_INTERFACE_H_
#define V1_ACTUATOR_FACTORY_INTERFACE_H_

#include "actuator_interface.h"

typedef struct {
  ActuatorInterface (*Make)(int id);
} ActuatorFactoryInterfaceStruct;
typedef const ActuatorFactoryInterfaceStruct* ActuatorFactoryInterface;

#endif  // V1_ACTUATOR_FACTORY_INTERFACE_H_
