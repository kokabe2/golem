// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_command.h"
#include "null_motor.h"
}

class NullMotorTest : public ::testing::Test {
 protected:
  Motor m;

  virtual void SetUp() { m = nullMotor->GetInstance(); }

  virtual void TearDown() { motor->Delete(&m); }
};

TEST_F(NullMotorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, motor->Id(m)); }

TEST_F(NullMotorTest, TagReturnsEmptyString) { EXPECT_STREQ("", motor->Tag(m)); }

TEST_F(NullMotorTest, StateReturnsEmptyString) { EXPECT_STREQ("", motor->State(m)); }

TEST_F(NullMotorTest, IsOnReturnsFalse) { EXPECT_FALSE(motor->IsOn(m)); }

TEST_F(NullMotorTest, MotorOnCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), motor->MotorOnCommand(m));
}

TEST_F(NullMotorTest, MotorOffCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), motor->MotorOffCommand(m));
}

TEST_F(NullMotorTest, MotorForceOffCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), motor->MotorForceOffCommand(m));
}

TEST_F(NullMotorTest, GetDirectionReturnsEmptyString) { EXPECT_STREQ("", motor->GetDirection(m)); }

TEST_F(NullMotorTest, SetDirectionHasNoEffect) {
  motor->SetDirection(m, "CW");

  EXPECT_STREQ("", motor->GetDirection(m));
}

TEST_F(NullMotorTest, GetSpeedReturnsZero) { EXPECT_EQ(0, motor->GetSpeed(m)); }

TEST_F(NullMotorTest, SetSpeedHasNoEffect) {
  motor->SetSpeed(m, 100);

  EXPECT_EQ(0, motor->GetSpeed(m));
}
