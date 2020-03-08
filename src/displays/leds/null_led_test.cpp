// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_led.h"
}

TEST(NullLedTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, nullLed->Id()); }

TEST(NullLedTest, TagReturnsEmptyString) { EXPECT_STREQ("", nullLed->Tag()); }

TEST(NullLedTest, TunrOffHasNoEffect) {
  nullLed->TurnOff();

  EXPECT_FALSE(nullLed->IsOff());
}

TEST(NullLedTest, TunrOnHasNoEffect) {
  nullLed->TurnOn();

  EXPECT_FALSE(nullLed->IsOn());
}

TEST(NullLedTest, IsOffReturnsFalse) { EXPECT_FALSE(nullLed->IsOff()); }

TEST(NullLedTest, IsOnReturnsFalse) { EXPECT_FALSE(nullLed->IsOn()); }
