// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_display.h"
}

class NullDisplayTest : public ::testing::Test {
 protected:
  Display display;

  virtual void SetUp() { display = nullDisplay->GetInstance(); }

  virtual void TearDown() { display->Delete(&display); }
};

TEST_F(NullDisplayTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, display->Id(display)); }

TEST_F(NullDisplayTest, TagReturnsEmptyString) { EXPECT_STREQ("", display->Tag(display)); }

TEST_F(NullDisplayTest, ResetHasNoEffect) {
  display->Reset(display);

  SUCCEED();
}
