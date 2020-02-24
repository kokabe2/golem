// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_temperature_sensor.h"
}

TEST(NullTemperatureSensorTest, NullObject) {
  EXPECT_EQ(~0, nullTemperatureSensor->Id());
  EXPECT_STREQ("", nullTemperatureSensor->Tag());
  EXPECT_STREQ("", nullTemperatureSensor->State());
  EXPECT_FALSE(nullTemperatureSensor->IsNormal());
}
