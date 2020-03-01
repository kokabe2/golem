// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_solenoid.h"
}

TEST(NullSolenoidTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, nullSolenoid->Id()); }

TEST(NullSolenoidTest, TagReturnsEmptyString) { EXPECT_STREQ("", nullSolenoid->Tag()); }

TEST(NullSolenoidTest, StateReturnsEmptyString) { EXPECT_STREQ("", nullSolenoid->State()); }

TEST(NullSolenoidTest, LockHasNoEffect) {
  nullSolenoid->Lock();

  EXPECT_FALSE(nullSolenoid->IsLocked());
}

TEST(NullSolenoidTest, UnlockHasNoEffect) { nullSolenoid->Unlock(); }

TEST(NullSolenoidTest, IsLockedReturnsFalse) { EXPECT_FALSE(nullSolenoid->IsLocked()); }
