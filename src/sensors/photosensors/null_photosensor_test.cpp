// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_photosensor.h"
}

class NullPhotosensorTest : public ::testing::Test {
 protected:
  Component c;

  virtual void SetUp() { c = nullPhotosensor->GetInstance(); }

  virtual void TearDown() { photosensor->Delete(&c); }
};

TEST_F(NullPhotosensorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, photosensor->Id(c)); }

TEST_F(NullPhotosensorTest, TagReturnsEmptyString) { EXPECT_STREQ("", photosensor->Tag(c)); }

TEST_F(NullPhotosensorTest, StateReturnsEmptyString) { EXPECT_STREQ("", photosensor->State(c)); }

TEST_F(NullPhotosensorTest, IsLightStateReturnsFalse) { EXPECT_FALSE(photosensor->IsLight(c)); }

TEST_F(NullPhotosensorTest, IsDarkStateReturnsFalse) { EXPECT_FALSE(photosensor->IsDark(c)); }
