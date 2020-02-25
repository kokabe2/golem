// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_motor.h"
}

TEST(NullMotorTest, NullObject) {
  EXPECT_EQ(~0, nullMotor->Id());
  EXPECT_STREQ("", nullMotor->Tag());
  EXPECT_STREQ("", nullMotor->State());

  EXPECT_FALSE(nullMotor->IsRunning());
  nullMotor->Run();
  EXPECT_FALSE(nullMotor->IsRunning());
  nullMotor->Stop();
  nullMotor->ForceStop();
  EXPECT_FALSE(nullMotor->IsRunning());

  EXPECT_FALSE(nullMotor->IsCw());
  nullMotor->SetToCw();
  EXPECT_FALSE(nullMotor->IsCw());
  nullMotor->SetToAcw();
  EXPECT_FALSE(nullMotor->IsCw());

  EXPECT_EQ(0, nullMotor->GetSpeed());
  nullMotor->SetSpeed(100);
  EXPECT_EQ(0, nullMotor->GetSpeed());
}
