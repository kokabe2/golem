// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_SOLENOID_FACTORY_INTERFACE_H_
#define V1_SOLENOID_FACTORY_INTERFACE_H_

#include "solenoid_interface.h"

typedef struct {
  SolenoidInterface (*Make)(int id);
} SolenoidFactoryInterfaceStruct;
typedef const SolenoidFactoryInterfaceStruct* SolenoidFactoryInterface;

#endif  // V1_SOLENOID_FACTORY_INTERFACE_H_
