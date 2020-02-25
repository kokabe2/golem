// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_dc_motor.h"
}

TEST(NullDcMotorTest, NullObject) {
  EXPECT_EQ(~0, nullDcMotor->Id());
  EXPECT_STREQ("", nullDcMotor->Tag());
  EXPECT_STREQ("", nullDcMotor->State());

  EXPECT_FALSE(nullDcMotor->IsRunning());
  nullDcMotor->Run();
  EXPECT_FALSE(nullDcMotor->IsRunning());
  nullDcMotor->Stop();
  nullDcMotor->ForceStop();
  EXPECT_FALSE(nullDcMotor->IsRunning());

  EXPECT_FALSE(nullDcMotor->IsCw());
  nullDcMotor->SetToCw();
  EXPECT_FALSE(nullDcMotor->IsCw());
  nullDcMotor->SetToAcw();
  EXPECT_FALSE(nullDcMotor->IsCw());

  EXPECT_EQ(0, nullDcMotor->GetSpeed());
  nullDcMotor->SetSpeed(100);
  EXPECT_EQ(0, nullDcMotor->GetSpeed());
}
