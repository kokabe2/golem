// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_photosensor.h"
}

TEST(NullPhotosensorTest, NullObject) {
  EXPECT_EQ(~0, nullPhotosensor->Id());
  EXPECT_STREQ("", nullPhotosensor->Tag());
  EXPECT_STREQ("", nullPhotosensor->State());
  EXPECT_FALSE(nullPhotosensor->IsLight());
  EXPECT_FALSE(nullPhotosensor->IsDark());
}
