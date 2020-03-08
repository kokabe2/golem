// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_led_array.h"
}

TEST(NullLedArrayTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, nullLedArray->Id()); }

TEST(NullLedArrayTest, TagReturnsEmptyString) { EXPECT_STREQ("", nullLedArray->Tag()); }

TEST(NullLedArrayTest, TunrAllOffHasNoEffect) {
  nullLedArray->TurnAllOff();

  EXPECT_FALSE(nullLedArray->IsAllOff());
}

TEST(NullLedArrayTest, TunrAllOnHasNoEffect) {
  nullLedArray->TurnAllOn();

  EXPECT_FALSE(nullLedArray->IsAllOn());
}

TEST(NullLedArrayTest, IsAllOffReturnsFalse) { EXPECT_FALSE(nullLedArray->IsAllOff()); }

TEST(NullLedArrayTest, IsAllOnReturnsFalse) { EXPECT_FALSE(nullLedArray->IsAllOn()); }

TEST(NullLedArrayTest, TunrOffHasNoEffect) {
  nullLedArray->TurnOff(0);

  EXPECT_FALSE(nullLedArray->IsOff(0));
}

TEST(NullLedArrayTest, TunrOnHasNoEffect) {
  nullLedArray->TurnOn(0);

  EXPECT_FALSE(nullLedArray->IsOn(0));
}

TEST(NullLedArrayTest, IsOffReturnsFalse) { EXPECT_FALSE(nullLedArray->IsOff(0)); }

TEST(NullLedArrayTest, IsOnReturnsFalse) { EXPECT_FALSE(nullLedArray->IsOn(0)); }
