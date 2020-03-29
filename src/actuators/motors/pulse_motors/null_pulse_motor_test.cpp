// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_command.h"
#include "null_pulse_motor.h"
}

class NullPulseMotorTest : public ::testing::Test {
 protected:
  PulseMotor pm;

  virtual void SetUp() { pm = nullPulseMotor->GetInstance(); }

  virtual void TearDown() { pulseMotor->Delete(&pm); }
};

TEST_F(NullPulseMotorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, pulseMotor->Id(pm)); }

TEST_F(NullPulseMotorTest, TagReturnsEmptyString) { EXPECT_STREQ("", pulseMotor->Tag(pm)); }

TEST_F(NullPulseMotorTest, StateReturnsEmptyString) { EXPECT_STREQ("", pulseMotor->State(pm)); }

TEST_F(NullPulseMotorTest, IsOnReturnsFalse) { EXPECT_FALSE(pulseMotor->IsOn(pm)); }

TEST_F(NullPulseMotorTest, PulseMotorOnCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), pulseMotor->PulseMotorOnCommand(pm));
}

TEST_F(NullPulseMotorTest, PulseMotorOffCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), pulseMotor->PulseMotorOffCommand(pm));
}

TEST_F(NullPulseMotorTest, PulseMotorForceOffCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), pulseMotor->PulseMotorForceOffCommand(pm));
}

TEST_F(NullPulseMotorTest, GetDirectionReturnsEmptyString) { EXPECT_STREQ("", pulseMotor->GetDirection(pm)); }

TEST_F(NullPulseMotorTest, SetDirectionHasNoEffect) {
  pulseMotor->SetDirection(pm, "CW");

  EXPECT_STREQ("", pulseMotor->GetDirection(pm));
}

TEST_F(NullPulseMotorTest, GetSpeedReturnsZero) { EXPECT_EQ(0, pulseMotor->GetSpeed(pm)); }

TEST_F(NullPulseMotorTest, SetSpeedHasNoEffect) {
  pulseMotor->SetSpeed(pm, 100);

  EXPECT_EQ(0, pulseMotor->GetSpeed(pm));
}

TEST_F(NullPulseMotorTest, PulseMotorStopCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), pulseMotor->PulseMotorStopCommand(pm, 0));
}

TEST_F(NullPulseMotorTest, PulseMotorWatchCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), pulseMotor->PulseMotorWatchCommand(pm, 0, NULL));
}

TEST_F(NullPulseMotorTest, GetModeReturnsEmptyString) { EXPECT_STREQ("", pulseMotor->GetMode(pm)); }

TEST_F(NullPulseMotorTest, SelectModeHasNoEffect) {
  pulseMotor->SelectMode(pm, "CW");

  EXPECT_STREQ("", pulseMotor->GetMode(pm));
}

TEST_F(NullPulseMotorTest, GetPulseRateReturnsZero) { EXPECT_EQ(0, pulseMotor->GetPulseRate(pm)); }

TEST_F(NullPulseMotorTest, SetPulseRateHasNoEffect) {
  pulseMotor->SetPulseRate(pm, 100);

  EXPECT_EQ(0, pulseMotor->GetPulseRate(pm));
}

TEST_F(NullPulseMotorTest, GetPositionReturnsZero) { EXPECT_EQ(0, pulseMotor->GetPosition(pm)); }
