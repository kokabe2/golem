// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_microswitch.h"
}

TEST(NullMicroswitchTest, NullObject) {
  EXPECT_EQ(~0, nullMicroswitch->Id());
  EXPECT_STREQ("", nullMicroswitch->Tag());
  EXPECT_STREQ("", nullMicroswitch->State());
  EXPECT_FALSE(nullMicroswitch->IsOff());
  EXPECT_FALSE(nullMicroswitch->IsOn());
}
