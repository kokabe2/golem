// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_ACTUATOR_TRANSACTION_FACTORY_INTERFACE_H_
#define V1_ACTUATOR_TRANSACTION_FACTORY_INTERFACE_H_

#include "actuator_interface.h"
#include "actuator_transaction_interface.h"
#include "sensor_interface.h"

typedef struct {
  ActuatorTransactionInterface (*MakeTimerTransaction)(
      ActuatorInterface ai, int time_in_milliseconds);
  ActuatorTransactionInterface (*MakeWatchSensorTransaction)(
      ActuatorInterface ai, SensorInterface si, int timeout_in_milliseconds);
} ActuatorTransactionFactoryInterfaceStruct;
typedef const ActuatorTransactionFactoryInterfaceStruct*
    ActuatorTransactionFactoryInterface;

#endif  // V1_ACTUATOR_TRANSACTION_FACTORY_INTERFACE_H_
