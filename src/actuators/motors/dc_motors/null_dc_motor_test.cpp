// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_dc_motor.h"
}

TEST(NullDcMotorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, nullDcMotor->Id()); }

TEST(NullDcMotorTest, TagReturnsEmptyString) { EXPECT_STREQ("", nullDcMotor->Tag()); }

TEST(NullDcMotorTest, StateReturnsEmptyString) { EXPECT_STREQ("", nullDcMotor->State()); }

TEST(NullDcMotorTest, RunHasNoEffect) {
  nullDcMotor->Run();

  EXPECT_FALSE(nullDcMotor->IsRunning());
}

TEST(NullDcMotorTest, StopHasNoEffect) { nullDcMotor->Stop(); }

TEST(NullDcMotorTest, IsRunningReturnsFalse) { EXPECT_FALSE(nullDcMotor->IsRunning()); }

TEST(NullDcMotorTest, ForceStopHasNoEffect) { nullDcMotor->ForceStop(); }

TEST(NullDcMotorTest, SetToCwpHasNoEffect) {
  nullDcMotor->SetToCw();

  EXPECT_FALSE(nullDcMotor->IsCw());
}

TEST(NullDcMotorTest, SetToAcwpHasNoEffect) { nullDcMotor->SetToAcw(); }

TEST(NullDcMotorTest, IsCwReturnsFalse) { EXPECT_FALSE(nullDcMotor->IsCw()); }

TEST(NullDcMotorTest, GetSpeedReturnsZero) { EXPECT_EQ(0, nullDcMotor->GetSpeed()); }

TEST(NullDcMotorTest, SetSpeedHasNoEffect) {
  nullDcMotor->SetSpeed(100);

  EXPECT_EQ(0, nullDcMotor->GetSpeed());
}
