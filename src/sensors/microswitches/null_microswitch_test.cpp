// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_command.h"
#include "null_microswitch.h"
}
class NullMicroswitchTest : public ::testing::Test {
 protected:
  Component c;

  virtual void SetUp() { c = nullMicroswitch->GetInstance(); }

  virtual void TearDown() { microswitch->Delete(&c); }
};

TEST_F(NullMicroswitchTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, microswitch->Id(c)); }

TEST_F(NullMicroswitchTest, TagReturnsEmptyString) { EXPECT_STREQ("", microswitch->Tag(c)); }

TEST_F(NullMicroswitchTest, MicroswitchWatchCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), microswitch->MicroswitchWatchCommand(c, "", NULL));
}

TEST_F(NullMicroswitchTest, StateReturnsEmptyString) { EXPECT_STREQ("", microswitch->State(c)); }

TEST_F(NullMicroswitchTest, IsOffStateReturnsFalse) { EXPECT_FALSE(microswitch->IsOff(c)); }

TEST_F(NullMicroswitchTest, IsOnStateReturnsFalse) { EXPECT_FALSE(microswitch->IsOn(c)); }
