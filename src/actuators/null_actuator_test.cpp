// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_actuator.h"
#include "null_command.h"
}

class NullActuatorTest : public ::testing::Test {
 protected:
  Actuator a;

  virtual void SetUp() { a = nullActuator->GetInstance(); }

  virtual void TearDown() { actuator->Delete(&a); }
};

TEST_F(NullActuatorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, actuator->Id(a)); }

TEST_F(NullActuatorTest, TagReturnsEmptyString) { EXPECT_STREQ("", actuator->Tag(a)); }

TEST_F(NullActuatorTest, StateReturnsEmptyString) { EXPECT_STREQ("", actuator->State(a)); }

TEST_F(NullActuatorTest, IsOnReturnsFalse) { EXPECT_FALSE(actuator->IsOn(a)); }

TEST_F(NullActuatorTest, ActuatorOnCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), actuator->ActuatorOnCommand(a));
}

TEST_F(NullActuatorTest, ActuatorOffCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), actuator->ActuatorOffCommand(a));
}

TEST_F(NullActuatorTest, ActuatorForceOffCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), actuator->ActuatorForceOffCommand(a));
}
