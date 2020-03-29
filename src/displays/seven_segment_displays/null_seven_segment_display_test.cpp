// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_seven_segment_display.h"
}

class NullSevenSegmentDisplayTest : public ::testing::Test {
 protected:
  SevenSegmentDisplay ssd;

  virtual void SetUp() { ssd = nullSevenSegmentDisplay->GetInstance(); }

  virtual void TearDown() { sevenSegmentDisplay->Delete(&ssd); }
};

TEST_F(NullSevenSegmentDisplayTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, sevenSegmentDisplay->Id(ssd)); }

TEST_F(NullSevenSegmentDisplayTest, TagReturnsEmptyString) { EXPECT_STREQ("", sevenSegmentDisplay->Tag(ssd)); }

TEST_F(NullSevenSegmentDisplayTest, ClearHasNoEffect) {
  sevenSegmentDisplay->Clear(ssd);

  SUCCEED();
}

TEST_F(NullSevenSegmentDisplayTest, GetReturnsZero) { EXPECT_EQ(0, sevenSegmentDisplay->Get(ssd)); }

TEST_F(NullSevenSegmentDisplayTest, SetHasNoEffect) {
  sevenSegmentDisplay->Set(ssd, '1');

  EXPECT_EQ(0, sevenSegmentDisplay->Get(ssd));
}
