// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_sensor.h"
}

TEST(NullSensorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, nullSensor->Id()); }

TEST(NullSensorTest, TagReturnsEmptyString) { EXPECT_STREQ("", nullSensor->Tag()); }

TEST(NullSensorTest, StateReturnsEmptyString) { EXPECT_STREQ("", nullSensor->State()); }

TEST(NullSensorTest, IsDefaultStateReturnsFalse) { EXPECT_FALSE(nullSensor->IsDefaultState()); }
