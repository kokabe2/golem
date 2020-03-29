// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_command.h"
#include "null_solenoid.h"
}

class NullSolenoidTest : public ::testing::Test {
 protected:
  Solenoid s;

  virtual void SetUp() { s = nullSolenoid->GetInstance(); }

  virtual void TearDown() { solenoid->Delete(&s); }
};

TEST_F(NullSolenoidTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, solenoid->Id(s)); }

TEST_F(NullSolenoidTest, TagReturnsEmptyString) { EXPECT_STREQ("", solenoid->Tag(s)); }

TEST_F(NullSolenoidTest, StateReturnsEmptyString) { EXPECT_STREQ("", solenoid->State(s)); }

TEST_F(NullSolenoidTest, IsOnReturnsFalse) { EXPECT_FALSE(solenoid->IsOn(s)); }

TEST_F(NullSolenoidTest, SolenoidOnCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), solenoid->SolenoidOnCommand(s));
}

TEST_F(NullSolenoidTest, SolenoidOffCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), solenoid->SolenoidOffCommand(s));
}

TEST_F(NullSolenoidTest, SolenoidForceOffCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), solenoid->SolenoidForceOffCommand(s));
}
