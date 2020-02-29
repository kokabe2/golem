// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_motor.h"
}

TEST(NullMotorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, nullMotor->Id()); }

TEST(NullMotorTest, TagReturnsEmptyString) { EXPECT_STREQ("", nullMotor->Tag()); }

TEST(NullMotorTest, StateReturnsEmptyString) { EXPECT_STREQ("", nullMotor->State()); }

TEST(NullMotorTest, RunHasNoEffect) {
  nullMotor->Run();

  EXPECT_FALSE(nullMotor->IsRunning());
}

TEST(NullMotorTest, StopHasNoEffect) { nullMotor->Stop(); }

TEST(NullMotorTest, IsRunningReturnsFalse) { EXPECT_FALSE(nullMotor->IsRunning()); }

TEST(NullMotorTest, ForceStopHasNoEffect) { nullMotor->ForceStop(); }

TEST(NullMotorTest, SetToCwpHasNoEffect) {
  nullMotor->SetToCw();

  EXPECT_FALSE(nullMotor->IsCw());
}

TEST(NullMotorTest, SetToAcwpHasNoEffect) { nullMotor->SetToAcw(); }

TEST(NullMotorTest, IsCwReturnsFalse) { EXPECT_FALSE(nullMotor->IsCw()); }

TEST(NullMotorTest, GetSpeedReturnsZero) { EXPECT_EQ(0, nullMotor->GetSpeed()); }

TEST(NullMotorTest, SetSpeedHasNoEffect) {
  nullMotor->SetSpeed(100);

  EXPECT_EQ(0, nullMotor->GetSpeed());
}
