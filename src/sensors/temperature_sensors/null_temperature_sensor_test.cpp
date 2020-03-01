// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_temperature_sensor.h"
}

TEST(NullTemperatureSensorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, nullTemperatureSensor->Id()); }

TEST(NullTemperatureSensorTest, TagReturnsEmptyString) { EXPECT_STREQ("", nullTemperatureSensor->Tag()); }

TEST(NullTemperatureSensorTest, StateReturnsEmptyString) { EXPECT_STREQ("", nullTemperatureSensor->State()); }

TEST(NullTemperatureSensorTest, IsNormalStateReturnsFalse) { EXPECT_FALSE(nullTemperatureSensor->IsNormal()); }
