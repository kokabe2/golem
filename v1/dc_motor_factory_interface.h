// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_DC_MOTOR_FACTORY_INTERFACE_H_
#define V1_DC_MOTOR_FACTORY_INTERFACE_H_

#include "dc_motor_interface.h"

typedef struct {
  DcMotorInterface (*Make)(int id);
} DcMotorFactoryInterfaceStruct;
typedef const DcMotorFactoryInterfaceStruct* DcMotorFactoryInterface;

#endif  // V1_DC_MOTOR_FACTORY_INTERFACE_H_
