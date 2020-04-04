// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_display.h"
}

class NullDisplayTest : public ::testing::Test {
 protected:
  Component c;

  virtual void SetUp() { c = nullDisplay->GetInstance(); }

  virtual void TearDown() { display->Delete(&c); }
};

TEST_F(NullDisplayTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, display->Id(c)); }

TEST_F(NullDisplayTest, TagReturnsEmptyString) { EXPECT_STREQ("", display->Tag(c)); }

TEST_F(NullDisplayTest, ResetHasNoEffect) {
  display->Reset(c);

  SUCCEED();
}
