// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_command.h"
#include "null_photosensor.h"
}

class NullPhotosensorTest : public ::testing::Test {
 protected:
  Photosensor p;

  virtual void SetUp() { p = nullPhotosensor->GetInstance(); }

  virtual void TearDown() { photosensor->Delete(&p); }
};

TEST_F(NullPhotosensorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, photosensor->Id(p)); }

TEST_F(NullPhotosensorTest, TagReturnsEmptyString) { EXPECT_STREQ("", photosensor->Tag(p)); }

TEST_F(NullPhotosensorTest, PhotosensorWatchCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), photosensor->PhotosensorWatchCommand(p, "", NULL));
}

TEST_F(NullPhotosensorTest, StateReturnsEmptyString) { EXPECT_STREQ("", photosensor->State(p)); }

TEST_F(NullPhotosensorTest, IsLightStateReturnsFalse) { EXPECT_FALSE(photosensor->IsLight(p)); }

TEST_F(NullPhotosensorTest, IsDarkStateReturnsFalse) { EXPECT_FALSE(photosensor->IsDark(p)); }
