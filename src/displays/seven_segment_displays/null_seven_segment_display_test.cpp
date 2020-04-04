// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_seven_segment_display.h"
}

class NullSevenSegmentDisplayTest : public ::testing::Test {
 protected:
  Component c;

  virtual void SetUp() { c = nullSevenSegmentDisplay->GetInstance(); }

  virtual void TearDown() { sevenSegmentDisplay->Delete(&c); }
};

TEST_F(NullSevenSegmentDisplayTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, sevenSegmentDisplay->Id(c)); }

TEST_F(NullSevenSegmentDisplayTest, TagReturnsEmptyString) { EXPECT_STREQ("", sevenSegmentDisplay->Tag(c)); }

TEST_F(NullSevenSegmentDisplayTest, ClearHasNoEffect) {
  sevenSegmentDisplay->Clear(c);

  SUCCEED();
}

TEST_F(NullSevenSegmentDisplayTest, GetReturnsZero) { EXPECT_EQ(0, sevenSegmentDisplay->Get(c)); }

TEST_F(NullSevenSegmentDisplayTest, SetHasNoEffect) {
  sevenSegmentDisplay->Set(c, '1');

  EXPECT_EQ(0, sevenSegmentDisplay->Get(c));
}
