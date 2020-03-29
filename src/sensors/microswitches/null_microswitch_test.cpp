// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_command.h"
#include "null_microswitch.h"
}
class NullMicroswitchTest : public ::testing::Test {
 protected:
  Microswitch m;

  virtual void SetUp() { m = nullMicroswitch->GetInstance(); }

  virtual void TearDown() { microswitch->Delete(&m); }
};

TEST_F(NullMicroswitchTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, microswitch->Id(m)); }

TEST_F(NullMicroswitchTest, TagReturnsEmptyString) { EXPECT_STREQ("", microswitch->Tag(m)); }

TEST_F(NullMicroswitchTest, MicroswitchWatchCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), microswitch->MicroswitchWatchCommand(m, "", NULL));
}

TEST_F(NullMicroswitchTest, StateReturnsEmptyString) { EXPECT_STREQ("", microswitch->State(m)); }

TEST_F(NullMicroswitchTest, IsOffStateReturnsFalse) { EXPECT_FALSE(microswitch->IsOff(m)); }

TEST_F(NullMicroswitchTest, IsOnStateReturnsFalse) { EXPECT_FALSE(microswitch->IsOn(m)); }
