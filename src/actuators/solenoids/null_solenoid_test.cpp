// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_solenoid.h"
}

class NullSolenoidTest : public ::testing::Test {
 protected:
  Solenoid solenoid;

  virtual void SetUp() { solenoid = nullSolenoid->GetInstance(); }

  virtual void TearDown() { solenoid->Delete(&solenoid); }
};

TEST_F(NullSolenoidTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, solenoid->Id(solenoid)); }

TEST_F(NullSolenoidTest, TagReturnsEmptyString) { EXPECT_STREQ("", solenoid->Tag(solenoid)); }

TEST_F(NullSolenoidTest, StateReturnsEmptyString) { EXPECT_STREQ("", solenoid->State(solenoid)); }

TEST_F(NullSolenoidTest, IsUnlockedReturnsTrue) { EXPECT_TRUE(solenoid->IsUnlocked(solenoid)); }

TEST_F(NullSolenoidTest, LockHasNoEffect) {
  solenoid->Lock(solenoid);

  EXPECT_TRUE(solenoid->IsUnlocked(solenoid));
}

TEST_F(NullSolenoidTest, UnlockHasNoEffect) { solenoid->Unlock(solenoid); }

TEST_F(NullSolenoidTest, ForceUnlockHasNoEffect) { solenoid->ForceUnlock(solenoid); }
