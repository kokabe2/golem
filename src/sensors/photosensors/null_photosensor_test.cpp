// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_photosensor.h"
}

class NullPhotosensorTest : public ::testing::Test {
 protected:
  Photosensor photosensor;

  virtual void SetUp() { photosensor = nullPhotosensor->GetInstance(); }

  virtual void TearDown() { photosensor->Delete(&photosensor); }
};

TEST_F(NullPhotosensorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, photosensor->Id(photosensor)); }

TEST_F(NullPhotosensorTest, TagReturnsEmptyString) { EXPECT_STREQ("", photosensor->Tag(photosensor)); }

TEST_F(NullPhotosensorTest, StateReturnsEmptyString) { EXPECT_STREQ("", photosensor->State(photosensor)); }

TEST_F(NullPhotosensorTest, IsLightStateReturnsFalse) { EXPECT_FALSE(photosensor->IsLight(photosensor)); }

TEST_F(NullPhotosensorTest, IsDarkStateReturnsFalse) { EXPECT_FALSE(photosensor->IsDark(photosensor)); }
