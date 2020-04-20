// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_microswitch.h"
}
class NullMicroswitchTest : public ::testing::Test {
 protected:
  Microswitch microswitch;

  virtual void SetUp() { microswitch = nullMicroswitch->GetInstance(); }

  virtual void TearDown() { microswitch->Delete(&microswitch); }
};

TEST_F(NullMicroswitchTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, microswitch->Id(microswitch)); }

TEST_F(NullMicroswitchTest, TagReturnsEmptyString) { EXPECT_STREQ("", microswitch->Tag(microswitch)); }

TEST_F(NullMicroswitchTest, StateReturnsEmptyString) { EXPECT_STREQ("", microswitch->State(microswitch)); }

TEST_F(NullMicroswitchTest, IsOffStateReturnsFalse) { EXPECT_FALSE(microswitch->IsOff(microswitch)); }

TEST_F(NullMicroswitchTest, IsOnStateReturnsFalse) { EXPECT_FALSE(microswitch->IsOn(microswitch)); }
