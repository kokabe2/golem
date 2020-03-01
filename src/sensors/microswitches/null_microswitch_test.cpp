// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_microswitch.h"
}

TEST(NullMicroswitchTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, nullMicroswitch->Id()); }

TEST(NullMicroswitchTest, TagReturnsEmptyString) { EXPECT_STREQ("", nullMicroswitch->Tag()); }

TEST(NullMicroswitchTest, StateReturnsEmptyString) { EXPECT_STREQ("", nullMicroswitch->State()); }

TEST(NullMicroswitchTest, IsOffStateReturnsFalse) { EXPECT_FALSE(nullMicroswitch->IsOff()); }

TEST(NullMicroswitchTest, IsOnStateReturnsFalse) { EXPECT_FALSE(nullMicroswitch->IsOn()); }
