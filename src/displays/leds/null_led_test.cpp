// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_led.h"
}

class NullLedTest : public ::testing::Test {
 protected:
  Led l;

  virtual void SetUp() { l = nullLed->GetInstance(); }

  virtual void TearDown() { led->Delete(&l); }
};

TEST_F(NullLedTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, led->Id(l)); }

TEST_F(NullLedTest, TagReturnsEmptyString) { EXPECT_STREQ("", led->Tag(l)); }

TEST_F(NullLedTest, TunrOffHasNoEffect) {
  led->TurnOff(l);

  EXPECT_FALSE(led->IsOff(l));
}

TEST_F(NullLedTest, TunrOnHasNoEffect) {
  led->TurnOn(l);

  EXPECT_FALSE(led->IsOn(l));
}

TEST_F(NullLedTest, IsOffReturnsFalse) { EXPECT_FALSE(led->IsOff(l)); }

TEST_F(NullLedTest, IsOnReturnsFalse) { EXPECT_FALSE(led->IsOn(l)); }
