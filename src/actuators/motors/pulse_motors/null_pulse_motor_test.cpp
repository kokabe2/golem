// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
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

TEST_F(NullPulseMotorTest, IsOffReturnsTrue) { EXPECT_TRUE(pulseMotor->IsOff(c)); }

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
