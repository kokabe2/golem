// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_PULSE_MOTOR_TRANSACTION_FACTORY_INTERFACE_H_
#define V1_PULSE_MOTOR_TRANSACTION_FACTORY_INTERFACE_H_

#include "actuator_transaction_interface.h"
#include "pulse_motor_interface.h"

typedef struct {
  ActuatorTransactionInterface (*MakePulseTransaction)(PulseMotorInterface pmi, int pulse);
} PulseMotorTransactionFactoryInterfaceStruct;
typedef const PulseMotorTransactionFactoryInterfaceStruct* PulseMotorTransactionFactoryInterface;

#endif  // V1_PULSE_MOTOR_TRANSACTION_FACTORY_INTERFACE_H_
