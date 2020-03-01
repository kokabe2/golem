// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_pulse_motor.h"
}

TEST(NullPulseMotorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, nullPulseMotor->Id()); }

TEST(NullPulseMotorTest, TagReturnsEmptyString) { EXPECT_STREQ("", nullPulseMotor->Tag()); }

TEST(NullPulseMotorTest, StateReturnsEmptyString) { EXPECT_STREQ("", nullPulseMotor->State()); }

TEST(NullPulseMotorTest, RunHasNoEffect) {
  nullPulseMotor->Run();

  EXPECT_FALSE(nullPulseMotor->IsRunning());
}

TEST(NullPulseMotorTest, StopHasNoEffect) { nullPulseMotor->Stop(); }

TEST(NullPulseMotorTest, IsRunningReturnsFalse) { EXPECT_FALSE(nullPulseMotor->IsRunning()); }

TEST(NullPulseMotorTest, ForceStopHasNoEffect) { nullPulseMotor->ForceStop(); }

TEST(NullPulseMotorTest, SetToCwpHasNoEffect) {
  nullPulseMotor->SetToCw();

  EXPECT_FALSE(nullPulseMotor->IsCw());
}

TEST(NullPulseMotorTest, SetToAcwpHasNoEffect) { nullPulseMotor->SetToAcw(); }

TEST(NullPulseMotorTest, IsCwReturnsFalse) { EXPECT_FALSE(nullPulseMotor->IsCw()); }

TEST(NullPulseMotorTest, GetSpeedReturnsZero) { EXPECT_EQ(0, nullPulseMotor->GetSpeed()); }

TEST(NullPulseMotorTest, SetSpeedHasNoEffect) {
  nullPulseMotor->SetSpeed(100);

  EXPECT_EQ(0, nullPulseMotor->GetSpeed());
}

TEST(NullPulseMotorTest, ExciteHasNoEffect) {
  nullPulseMotor->Excite();

  EXPECT_FALSE(nullPulseMotor->IsExciting());
}

TEST(NullPulseMotorTest, UnexciteHasNoEffect) { nullPulseMotor->Unexcite(); }

TEST(NullPulseMotorTest, GetPulseRateReturnsZero) { EXPECT_EQ(0, nullPulseMotor->GetPulseRate()); }

TEST(NullPulseMotorTest, SetPulseRateHasNoEffect) {
  nullPulseMotor->SetSpeed(100);

  EXPECT_EQ(0, nullPulseMotor->GetPulseRate());
}

TEST(NullPulseMotorTest, GetPositionReturnsZero) { EXPECT_EQ(0, nullPulseMotor->GetPosition()); }

TEST(NullPulseMotorTest, MoveHasNoEffect) {
  nullPulseMotor->Move(100);

  EXPECT_EQ(0, nullPulseMotor->GetPosition());
}
