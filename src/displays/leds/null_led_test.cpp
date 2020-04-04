// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_led.h"
}

class NullLedTest : public ::testing::Test {
 protected:
  Component c;

  virtual void SetUp() { c = nullLed->GetInstance(); }

  virtual void TearDown() { led->Delete(&c); }
};

TEST_F(NullLedTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, led->Id(c)); }

TEST_F(NullLedTest, TagReturnsEmptyString) { EXPECT_STREQ("", led->Tag(c)); }

TEST_F(NullLedTest, TunrOffHasNoEffect) {
  led->TurnOff(c);

  EXPECT_FALSE(led->IsOff(c));
}

TEST_F(NullLedTest, TunrOnHasNoEffect) {
  led->TurnOn(c);

  EXPECT_FALSE(led->IsOn(c));
}

TEST_F(NullLedTest, IsOffReturnsFalse) { EXPECT_FALSE(led->IsOff(c)); }

TEST_F(NullLedTest, IsOnReturnsFalse) { EXPECT_FALSE(led->IsOn(c)); }
