// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_actuator.h"
}

class NullActuatorTest : public ::testing::Test {
 protected:
  Actuator actuator;

  virtual void SetUp() { actuator = nullActuator->GetInstance(); }

  virtual void TearDown() { actuator->Delete(&actuator); }
};

TEST_F(NullActuatorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, actuator->Id(actuator)); }

TEST_F(NullActuatorTest, TagReturnsEmptyString) { EXPECT_STREQ("", actuator->Tag(actuator)); }

TEST_F(NullActuatorTest, StateReturnsEmptyString) { EXPECT_STREQ("", actuator->State(actuator)); }

TEST_F(NullActuatorTest, IsOffReturnsTrue) { EXPECT_TRUE(actuator->IsOff(actuator)); }

TEST_F(NullActuatorTest, TurnOnHasNoEffect) {
  actuator->TurnOn(actuator);

  EXPECT_TRUE(actuator->IsOff(actuator));
}

TEST_F(NullActuatorTest, TurnOffHasNoEffect) { actuator->TurnOff(actuator); }

TEST_F(NullActuatorTest, ForceTurnOffHasNoEffect) { actuator->ForceTurnOff(actuator); }
