// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_temperature_sensor.h"
}

class NullTemperatureSensorTest : public ::testing::Test {
 protected:
  TemperatureSensor sensor;

  virtual void SetUp() { sensor = nullTemperatureSensor->GetInstance(); }

  virtual void TearDown() { sensor->Delete(&sensor); }
};

TEST_F(NullTemperatureSensorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, sensor->Id(sensor)); }

TEST_F(NullTemperatureSensorTest, TagReturnsEmptyString) { EXPECT_STREQ("", sensor->Tag(sensor)); }

TEST_F(NullTemperatureSensorTest, StateReturnsEmptyString) { EXPECT_STREQ("", sensor->State(sensor)); }

TEST_F(NullTemperatureSensorTest, IsNormalStateReturnsFalse) { EXPECT_FALSE(sensor->IsNormal(sensor)); }
