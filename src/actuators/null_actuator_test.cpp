// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_actuator.h"
}

class NullActuatorTest : public ::testing::Test {
 protected:
  Component c;

  virtual void SetUp() { c = nullActuator->GetInstance(); }

  virtual void TearDown() { actuator->Delete(&c); }
};

TEST_F(NullActuatorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, actuator->Id(c)); }

TEST_F(NullActuatorTest, TagReturnsEmptyString) { EXPECT_STREQ("", actuator->Tag(c)); }

TEST_F(NullActuatorTest, StateReturnsEmptyString) { EXPECT_STREQ("", actuator->State(c)); }

TEST_F(NullActuatorTest, IsOnReturnsFalse) { EXPECT_FALSE(actuator->IsOn(c)); }
