// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_pulse_motor.h"
}

class NullPulseMotorTest : public ::testing::Test {
 protected:
  PulseMotor motor;

  virtual void SetUp() { motor = nullPulseMotor->GetInstance(); }

  virtual void TearDown() { motor->Delete(&motor); }
};

TEST_F(NullPulseMotorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, motor->Id(motor)); }

TEST_F(NullPulseMotorTest, TagReturnsEmptyString) { EXPECT_STREQ("", motor->Tag(motor)); }

TEST_F(NullPulseMotorTest, StateReturnsEmptyString) { EXPECT_STREQ("", motor->State(motor)); }

TEST_F(NullPulseMotorTest, IsStoppedReturnsTrue) { EXPECT_TRUE(motor->IsStopped(motor)); }

TEST_F(NullPulseMotorTest, RunHasNoEffect) {
  motor->Run(motor);

  EXPECT_TRUE(motor->IsStopped(motor));
}

TEST_F(NullPulseMotorTest, StopHasNoEffect) { motor->Stop(motor); }

TEST_F(NullPulseMotorTest, ForceStopHasNoEffect) { motor->ForceStop(motor); }

TEST_F(NullPulseMotorTest, GetDirectionReturnsEmptyString) { EXPECT_STREQ("", motor->GetDirection(motor)); }

TEST_F(NullPulseMotorTest, SetDirectionHasNoEffect) {
  motor->SetDirection(motor, "CW");

  EXPECT_STREQ("", motor->GetDirection(motor));
}

TEST_F(NullPulseMotorTest, GetSpeedReturnsZero) { EXPECT_EQ(0, motor->GetSpeed(motor)); }

TEST_F(NullPulseMotorTest, SetSpeedHasNoEffect) {
  motor->SetSpeed(motor, 100);

  EXPECT_EQ(0, motor->GetSpeed(motor));
}

TEST_F(NullPulseMotorTest, GetModeReturnsEmptyString) { EXPECT_STREQ("", motor->GetMode(motor)); }

TEST_F(NullPulseMotorTest, SelectModeHasNoEffect) {
  motor->SelectMode(motor, "CW");

  EXPECT_STREQ("", motor->GetMode(motor));
}

TEST_F(NullPulseMotorTest, GetPulseRateReturnsZero) { EXPECT_EQ(0, motor->GetPulseRate(motor)); }

TEST_F(NullPulseMotorTest, SetPulseRateHasNoEffect) {
  motor->SetPulseRate(motor, 100);

  EXPECT_EQ(0, motor->GetPulseRate(motor));
}

TEST_F(NullPulseMotorTest, GetPositionReturnsZero) { EXPECT_EQ(0, motor->GetPosition(motor)); }
