// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_sensor.h"
}

TEST(NullSensorTest, NullObject) {
  EXPECT_EQ(~0, nullSensor->Id());
  EXPECT_STREQ("", nullSensor->Tag());
  EXPECT_STREQ("", nullSensor->State());
  EXPECT_FALSE(nullSensor->IsDefaultState());
}
