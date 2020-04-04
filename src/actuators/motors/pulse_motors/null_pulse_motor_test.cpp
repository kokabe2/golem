// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_command.h"
#include "null_pulse_motor.h"
}

class NullPulseMotorTest : public ::testing::Test {
 protected:
  Component c;

  virtual void SetUp() { c = nullPulseMotor->GetInstance(); }

  virtual void TearDown() { pulseMotor->Delete(&c); }
};

TEST_F(NullPulseMotorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, pulseMotor->Id(c)); }

TEST_F(NullPulseMotorTest, TagReturnsEmptyString) { EXPECT_STREQ("", pulseMotor->Tag(c)); }

TEST_F(NullPulseMotorTest, StateReturnsEmptyString) { EXPECT_STREQ("", pulseMotor->State(c)); }

TEST_F(NullPulseMotorTest, IsOnReturnsFalse) { EXPECT_FALSE(pulseMotor->IsOn(c)); }

TEST_F(NullPulseMotorTest, PulseMotorOnCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), pulseMotor->PulseMotorOnCommand(c));
}

TEST_F(NullPulseMotorTest, PulseMotorOffCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), pulseMotor->PulseMotorOffCommand(c));
}

TEST_F(NullPulseMotorTest, PulseMotorForceOffCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), pulseMotor->PulseMotorForceOffCommand(c));
}

TEST_F(NullPulseMotorTest, GetDirectionReturnsEmptyString) { EXPECT_STREQ("", pulseMotor->GetDirection(c)); }

TEST_F(NullPulseMotorTest, SetDirectionHasNoEffect) {
  pulseMotor->SetDirection(c, "CW");

  EXPECT_STREQ("", pulseMotor->GetDirection(c));
}

TEST_F(NullPulseMotorTest, GetSpeedReturnsZero) { EXPECT_EQ(0, pulseMotor->GetSpeed(c)); }

TEST_F(NullPulseMotorTest, SetSpeedHasNoEffect) {
  pulseMotor->SetSpeed(c, 100);

  EXPECT_EQ(0, pulseMotor->GetSpeed(c));
}

TEST_F(NullPulseMotorTest, PulseMotorStopCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), pulseMotor->PulseMotorStopCommand(c, 0));
}

TEST_F(NullPulseMotorTest, PulseMotorWatchCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), pulseMotor->PulseMotorWatchCommand(c, 0, NULL));
}

TEST_F(NullPulseMotorTest, GetModeReturnsEmptyString) { EXPECT_STREQ("", pulseMotor->GetMode(c)); }

TEST_F(NullPulseMotorTest, SelectModeHasNoEffect) {
  pulseMotor->SelectMode(c, "CW");

  EXPECT_STREQ("", pulseMotor->GetMode(c));
}

TEST_F(NullPulseMotorTest, GetPulseRateReturnsZero) { EXPECT_EQ(0, pulseMotor->GetPulseRate(c)); }

TEST_F(NullPulseMotorTest, SetPulseRateHasNoEffect) {
  pulseMotor->SetPulseRate(c, 100);

  EXPECT_EQ(0, pulseMotor->GetPulseRate(c));
}

TEST_F(NullPulseMotorTest, GetPositionReturnsZero) { EXPECT_EQ(0, pulseMotor->GetPosition(c)); }
