// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_led_array.h"
}

class NullLedArrayTest : public ::testing::Test {
 protected:
  LedArray la;

  virtual void SetUp() { la = nullLedArray->GetInstance(); }

  virtual void TearDown() { ledArray->Delete(&la); }
};

TEST_F(NullLedArrayTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, ledArray->Id(la)); }

TEST_F(NullLedArrayTest, TagReturnsEmptyString) { EXPECT_STREQ("", ledArray->Tag(la)); }

TEST_F(NullLedArrayTest, TunrAllOffHasNoEffect) {
  ledArray->TurnAllOff(la);

  EXPECT_FALSE(ledArray->IsAllOff(la));
}

TEST_F(NullLedArrayTest, TunrAllOnHasNoEffect) {
  ledArray->TurnAllOn(la);

  EXPECT_FALSE(ledArray->IsAllOn(la));
}

TEST_F(NullLedArrayTest, IsAllOffReturnsFalse) { EXPECT_FALSE(ledArray->IsAllOff(la)); }

TEST_F(NullLedArrayTest, IsAllOnReturnsFalse) { EXPECT_FALSE(ledArray->IsAllOn(la)); }

TEST_F(NullLedArrayTest, TunrOffHasNoEffect) {
  ledArray->TurnOff(la, 0);

  EXPECT_FALSE(ledArray->IsOff(la, 0));
}

TEST_F(NullLedArrayTest, TunrOnHasNoEffect) {
  ledArray->TurnOn(la, 0);

  EXPECT_FALSE(ledArray->IsOn(la, 0));
}

TEST_F(NullLedArrayTest, IsOffReturnsFalse) { EXPECT_FALSE(ledArray->IsOff(la, 0)); }

TEST_F(NullLedArrayTest, IsOnReturnsFalse) { EXPECT_FALSE(ledArray->IsOn(la, 0)); }
