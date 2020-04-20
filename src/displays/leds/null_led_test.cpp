// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_led.h"
}

class NullLedTest : public ::testing::Test {
 protected:
  Led led;

  virtual void SetUp() { led = nullLed->GetInstance(); }

  virtual void TearDown() { led->Delete(&led); }
};

TEST_F(NullLedTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, led->Id(led)); }

TEST_F(NullLedTest, TagReturnsEmptyString) { EXPECT_STREQ("", led->Tag(led)); }

TEST_F(NullLedTest, TunrOffHasNoEffect) {
  led->TurnOff(led);

  EXPECT_FALSE(led->IsOff(led));
}

TEST_F(NullLedTest, TunrOnHasNoEffect) {
  led->TurnOn(led);

  EXPECT_FALSE(led->IsOn(led));
}

TEST_F(NullLedTest, IsOffReturnsFalse) { EXPECT_FALSE(led->IsOff(led)); }

TEST_F(NullLedTest, IsOnReturnsFalse) { EXPECT_FALSE(led->IsOn(led)); }
