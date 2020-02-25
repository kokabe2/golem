// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_solenoid.h"
}

TEST(NullSolenoidTest, NullObject) {
  EXPECT_EQ(~0, nullSolenoid->Id());
  EXPECT_STREQ("", nullSolenoid->Tag());
  EXPECT_STREQ("", nullSolenoid->State());
  EXPECT_FALSE(nullSolenoid->IsLocked());
  nullSolenoid->Lock();
  EXPECT_FALSE(nullSolenoid->IsLocked());
  nullSolenoid->Unlock();
  EXPECT_FALSE(nullSolenoid->IsLocked());
}
