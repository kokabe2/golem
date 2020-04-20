// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_motor.h"
}

class NullMotorTest : public ::testing::Test {
 protected:
  Motor motor;

  virtual void SetUp() { motor = nullMotor->GetInstance(); }

  virtual void TearDown() { motor->Delete(&motor); }
};

TEST_F(NullMotorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, motor->Id(motor)); }

TEST_F(NullMotorTest, TagReturnsEmptyString) { EXPECT_STREQ("", motor->Tag(motor)); }

TEST_F(NullMotorTest, StateReturnsEmptyString) { EXPECT_STREQ("", motor->State(motor)); }

TEST_F(NullMotorTest, IsStoppedReturnsTrue) { EXPECT_TRUE(motor->IsStopped(motor)); }

TEST_F(NullMotorTest, RunHasNoEffect) {
  motor->Run(motor);

  EXPECT_TRUE(motor->IsStopped(motor));
}

TEST_F(NullMotorTest, StopHasNoEffect) { motor->Stop(motor); }

TEST_F(NullMotorTest, ForceStopHasNoEffect) { motor->ForceStop(motor); }

TEST_F(NullMotorTest, GetDirectionReturnsEmptyString) { EXPECT_STREQ("", motor->GetDirection(motor)); }

TEST_F(NullMotorTest, SetDirectionHasNoEffect) {
  motor->SetDirection(motor, "CW");

  EXPECT_STREQ("", motor->GetDirection(motor));
}

TEST_F(NullMotorTest, GetSpeedReturnsZero) { EXPECT_EQ(0, motor->GetSpeed(motor)); }

TEST_F(NullMotorTest, SetSpeedHasNoEffect) {
  motor->SetSpeed(motor, 100);

  EXPECT_EQ(0, motor->GetSpeed(motor));
}
