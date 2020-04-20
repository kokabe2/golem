// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_seven_segment_display.h"
}

class NullSevenSegmentDisplayTest : public ::testing::Test {
 protected:
  SevenSegmentDisplay display;

  virtual void SetUp() { display = nullSevenSegmentDisplay->GetInstance(); }

  virtual void TearDown() { display->Delete(&display); }
};

TEST_F(NullSevenSegmentDisplayTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, display->Id(display)); }

TEST_F(NullSevenSegmentDisplayTest, TagReturnsEmptyString) { EXPECT_STREQ("", display->Tag(display)); }

TEST_F(NullSevenSegmentDisplayTest, ClearHasNoEffect) {
  display->Clear(display);

  SUCCEED();
}

TEST_F(NullSevenSegmentDisplayTest, GetReturnsZero) { EXPECT_EQ(0, display->Get(display)); }

TEST_F(NullSevenSegmentDisplayTest, SetHasNoEffect) {
  display->Set(display, '1');

  EXPECT_EQ(0, display->Get(display));
}
