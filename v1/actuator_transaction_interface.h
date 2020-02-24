// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_ACTUATOR_TRANSACTION_INTERFACE_H_
#define V1_ACTUATOR_TRANSACTION_INTERFACE_H_

#include <stdbool.h>

typedef struct {
  bool (*Execute)(void);  //
} ActuatorTransactionInterfaceStruct;
typedef const ActuatorTransactionInterfaceStruct* ActuatorTransactionInterface;

#endif  // V1_ACTUATOR_TRANSACTION_INTERFACE_H_
