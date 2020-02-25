// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_MOTOR_FACTORY_INTERFACE_H_
#define V1_MOTOR_FACTORY_INTERFACE_H_

#include "motor_interface.h"

typedef struct {
  MotorInterface (*Make)(int id);  //
} MotorFactoryInterfaceStruct;
typedef const MotorFactoryInterfaceStruct* MotorFactoryInterface;

#endif  // V1_MOTOR_FACTORY_INTERFACE_H_
