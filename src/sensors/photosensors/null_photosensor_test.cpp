// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_photosensor.h"
}

TEST(NullPhotosensorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, nullPhotosensor->Id()); }

TEST(NullPhotosensorTest, TagReturnsEmptyString) { EXPECT_STREQ("", nullPhotosensor->Tag()); }

TEST(NullPhotosensorTest, StateReturnsEmptyString) { EXPECT_STREQ("", nullPhotosensor->State()); }

TEST(NullPhotosensorTest, IsLightStateReturnsFalse) { EXPECT_FALSE(nullPhotosensor->IsLight()); }

TEST(NullPhotosensorTest, IsDarkStateReturnsFalse) { EXPECT_FALSE(nullPhotosensor->IsDark()); }
