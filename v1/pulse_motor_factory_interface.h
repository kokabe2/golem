// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_PULSE_MOTOR_FACTORY_INTERFACE_H_
#define V1_PULSE_MOTOR_FACTORY_INTERFACE_H_

#include "pulse_motor_interface.h"

typedef struct {
  PulseMotorInterface (*Make)(int id);
} PulseMotorFactoryInterfaceStruct;
typedef const PulseMotorFactoryInterfaceStruct* PulseMotorFactoryInterface;

#endif  // V1_PULSE_MOTOR_FACTORY_INTERFACE_H_
