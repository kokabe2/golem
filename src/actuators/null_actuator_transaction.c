// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "null_actuator_transaction.h"

static bool False(void) { return false; }

static const ActuatorTransactionInterfaceStruct kTheMethod = {
    .Execute = False,
};

const ActuatorTransactionInterface nullActuatorTransaction = &kTheMethod;
