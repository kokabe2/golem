// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_led_array.h"
}

class NullLedArrayTest : public ::testing::Test {
 protected:
  LedArray leds;

  virtual void SetUp() { leds = nullLedArray->GetInstance(); }

  virtual void TearDown() { leds->Delete(&leds); }
};

TEST_F(NullLedArrayTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, leds->Id(leds)); }

TEST_F(NullLedArrayTest, TagReturnsEmptyString) { EXPECT_STREQ("", leds->Tag(leds)); }

TEST_F(NullLedArrayTest, TunrAllOffHasNoEffect) {
  leds->TurnAllOff(leds);

  EXPECT_FALSE(leds->IsAllOff(leds));
}

TEST_F(NullLedArrayTest, TunrAllOnHasNoEffect) {
  leds->TurnAllOn(leds);

  EXPECT_FALSE(leds->IsAllOn(leds));
}

TEST_F(NullLedArrayTest, IsAllOffReturnsFalse) { EXPECT_FALSE(leds->IsAllOff(leds)); }

TEST_F(NullLedArrayTest, IsAllOnReturnsFalse) { EXPECT_FALSE(leds->IsAllOn(leds)); }

TEST_F(NullLedArrayTest, TunrOffHasNoEffect) {
  leds->TurnOff(leds, 0);

  EXPECT_FALSE(leds->IsOff(leds, 0));
}

TEST_F(NullLedArrayTest, TunrOnHasNoEffect) {
  leds->TurnOn(leds, 0);

  EXPECT_FALSE(leds->IsOn(leds, 0));
}

TEST_F(NullLedArrayTest, IsOffReturnsFalse) { EXPECT_FALSE(leds->IsOff(leds, 0)); }

TEST_F(NullLedArrayTest, IsOnReturnsFalse) { EXPECT_FALSE(leds->IsOn(leds, 0)); }
