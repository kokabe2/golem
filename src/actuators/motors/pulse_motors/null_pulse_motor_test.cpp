// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_pulse_motor.h"
}

TEST(NullPulseMotorTest, NullObject) {
  EXPECT_EQ(~0, nullPulseMotor->Id());
  EXPECT_STREQ("", nullPulseMotor->Tag());
  EXPECT_STREQ("", nullPulseMotor->State());

  EXPECT_FALSE(nullPulseMotor->IsRunning());
  nullPulseMotor->Run();
  EXPECT_FALSE(nullPulseMotor->IsRunning());
  nullPulseMotor->Stop();
  nullPulseMotor->ForceStop();
  EXPECT_FALSE(nullPulseMotor->IsRunning());

  EXPECT_FALSE(nullPulseMotor->IsCw());
  nullPulseMotor->SetToCw();
  EXPECT_FALSE(nullPulseMotor->IsCw());
  nullPulseMotor->SetToAcw();
  EXPECT_FALSE(nullPulseMotor->IsCw());

  EXPECT_EQ(0, nullPulseMotor->GetSpeed());
  nullPulseMotor->SetSpeed(100);
  EXPECT_EQ(0, nullPulseMotor->GetSpeed());

  EXPECT_FALSE(nullPulseMotor->IsExciting());
  nullPulseMotor->Excite();
  EXPECT_FALSE(nullPulseMotor->IsExciting());
  nullPulseMotor->Unexcite();
  nullPulseMotor->ForceStop();
  EXPECT_FALSE(nullPulseMotor->IsExciting());

  EXPECT_EQ(0, nullPulseMotor->GetPulseRate());
  nullPulseMotor->SetPulseRate(100);
  EXPECT_EQ(0, nullPulseMotor->GetPulseRate());

  EXPECT_EQ(0, nullPulseMotor->GetPosition());
  nullPulseMotor->Move(100);
  EXPECT_EQ(0, nullPulseMotor->GetPosition());
}
