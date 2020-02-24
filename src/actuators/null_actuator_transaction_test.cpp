// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_actuator_transaction.h"
}

TEST(NullActuatorTransactionTest, NullObject) {
  EXPECT_FALSE(nullActuatorTransaction->Execute());
}
