// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_display.h"
}

TEST(NullDisplayTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, nullDisplay->Id()); }

TEST(NullDisplayTest, TagReturnsEmptyString) { EXPECT_STREQ("", nullDisplay->Tag()); }

TEST(NullDisplayTest, ResetHasNoEffect) {
  nullDisplay->Reset();

  SUCCEED();
}
