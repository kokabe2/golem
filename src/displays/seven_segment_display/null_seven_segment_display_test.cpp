// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_seven_segment_display.h"
}

TEST(NullSevenSegmentDisplayTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, nullSevenSegmentDisplay->Id()); }

TEST(NullSevenSegmentDisplayTest, TagReturnsEmptyString) { EXPECT_STREQ("", nullSevenSegmentDisplay->Tag()); }

TEST(NullSevenSegmentDisplayTest, ClearHasNoEffect) {
  nullSevenSegmentDisplay->Clear();

  SUCCEED();
}

TEST(NullSevenSegmentDisplayTest, GetReturnsZero) { EXPECT_EQ(0, nullSevenSegmentDisplay->Get()); }

TEST(NullSevenSegmentDisplayTest, SetHasNoEffect) {
  nullSevenSegmentDisplay->Set('1');

  EXPECT_EQ(0, nullSevenSegmentDisplay->Get());
}
