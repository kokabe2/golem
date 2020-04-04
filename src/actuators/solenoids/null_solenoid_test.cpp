// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_solenoid.h"
}

class NullSolenoidTest : public ::testing::Test {
 protected:
  Component c;

  virtual void SetUp() { c = nullSolenoid->GetInstance(); }

  virtual void TearDown() { solenoid->Delete(&c); }
};

TEST_F(NullSolenoidTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, solenoid->Id(c)); }

TEST_F(NullSolenoidTest, TagReturnsEmptyString) { EXPECT_STREQ("", solenoid->Tag(c)); }

TEST_F(NullSolenoidTest, StateReturnsEmptyString) { EXPECT_STREQ("", solenoid->State(c)); }

TEST_F(NullSolenoidTest, IsUnlockedReturnsTrue) { EXPECT_TRUE(solenoid->IsUnlocked(c)); }

TEST_F(NullSolenoidTest, LockHasNoEffect) {
  solenoid->Lock(c);

  EXPECT_TRUE(solenoid->IsUnlocked(c));
}

TEST_F(NullSolenoidTest, UnlockHasNoEffect) { solenoid->Unlock(c); }

TEST_F(NullSolenoidTest, ForceUnlockHasNoEffect) { solenoid->ForceUnlock(c); }
