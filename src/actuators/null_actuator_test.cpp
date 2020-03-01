// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_actuator.h"
}

TEST(NullActuatorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, nullActuator->Id()); }

TEST(NullActuatorTest, TagReturnsEmptyString) { EXPECT_STREQ("", nullActuator->Tag()); }

TEST(NullActuatorTest, StateReturnsEmptyString) { EXPECT_STREQ("", nullActuator->State()); }

TEST(NullActuatorTest, ActivateHasNoEffect) {
  nullActuator->Activate();

  EXPECT_FALSE(nullActuator->IsActive());
}

TEST(NullActuatorTest, DeactivateHasNoEffect) { nullActuator->Deactivate(); }

TEST(NullActuatorTest, IsActiveReturnsFalse) { EXPECT_FALSE(nullActuator->IsActive()); }
