// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_led_array.h"
}

class NullLedArrayTest : public ::testing::Test {
 protected:
  Component c;

  virtual void SetUp() { c = nullLedArray->GetInstance(); }

  virtual void TearDown() { ledArray->Delete(&c); }
};

TEST_F(NullLedArrayTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, ledArray->Id(c)); }

TEST_F(NullLedArrayTest, TagReturnsEmptyString) { EXPECT_STREQ("", ledArray->Tag(c)); }

TEST_F(NullLedArrayTest, TunrAllOffHasNoEffect) {
  ledArray->TurnAllOff(c);

  EXPECT_FALSE(ledArray->IsAllOff(c));
}

TEST_F(NullLedArrayTest, TunrAllOnHasNoEffect) {
  ledArray->TurnAllOn(c);

  EXPECT_FALSE(ledArray->IsAllOn(c));
}

TEST_F(NullLedArrayTest, IsAllOffReturnsFalse) { EXPECT_FALSE(ledArray->IsAllOff(c)); }

TEST_F(NullLedArrayTest, IsAllOnReturnsFalse) { EXPECT_FALSE(ledArray->IsAllOn(c)); }

TEST_F(NullLedArrayTest, TunrOffHasNoEffect) {
  ledArray->TurnOff(c, 0);

  EXPECT_FALSE(ledArray->IsOff(c, 0));
}

TEST_F(NullLedArrayTest, TunrOnHasNoEffect) {
  ledArray->TurnOn(c, 0);

  EXPECT_FALSE(ledArray->IsOn(c, 0));
}

TEST_F(NullLedArrayTest, IsOffReturnsFalse) { EXPECT_FALSE(ledArray->IsOff(c, 0)); }

TEST_F(NullLedArrayTest, IsOnReturnsFalse) { EXPECT_FALSE(ledArray->IsOn(c, 0)); }
