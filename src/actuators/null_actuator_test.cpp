// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_actuator.h"
}

TEST(NullActuatorTest, NullObject) {
  EXPECT_EQ(~0, nullActuator->Id());
  EXPECT_STREQ("", nullActuator->Tag());
  EXPECT_STREQ("", nullActuator->State());

  EXPECT_FALSE(nullActuator->IsActive());
  nullActuator->Activate();
  EXPECT_FALSE(nullActuator->IsActive());
  nullActuator->Deactivate();
  EXPECT_FALSE(nullActuator->IsActive());
}
