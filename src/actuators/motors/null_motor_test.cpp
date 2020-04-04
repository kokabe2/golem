// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_motor.h"
}

class NullMotorTest : public ::testing::Test {
 protected:
  Component c;

  virtual void SetUp() { c = nullMotor->GetInstance(); }

  virtual void TearDown() { motor->Delete(&c); }
};

TEST_F(NullMotorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, motor->Id(c)); }

TEST_F(NullMotorTest, TagReturnsEmptyString) { EXPECT_STREQ("", motor->Tag(c)); }

TEST_F(NullMotorTest, StateReturnsEmptyString) { EXPECT_STREQ("", motor->State(c)); }

TEST_F(NullMotorTest, IsOnReturnsFalse) { EXPECT_FALSE(motor->IsOn(c)); }

TEST_F(NullMotorTest, GetDirectionReturnsEmptyString) { EXPECT_STREQ("", motor->GetDirection(c)); }

TEST_F(NullMotorTest, SetDirectionHasNoEffect) {
  motor->SetDirection(c, "CW");

  EXPECT_STREQ("", motor->GetDirection(c));
}

TEST_F(NullMotorTest, GetSpeedReturnsZero) { EXPECT_EQ(0, motor->GetSpeed(c)); }

TEST_F(NullMotorTest, SetSpeedHasNoEffect) {
  motor->SetSpeed(c, 100);

  EXPECT_EQ(0, motor->GetSpeed(c));
}
