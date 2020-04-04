// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_temperature_sensor.h"
}

class NullTemperatureSensorTest : public ::testing::Test {
 protected:
  Component c;

  virtual void SetUp() { c = nullTemperatureSensor->GetInstance(); }

  virtual void TearDown() { temperatureSensor->Delete(&c); }
};

TEST_F(NullTemperatureSensorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, temperatureSensor->Id(c)); }

TEST_F(NullTemperatureSensorTest, TagReturnsEmptyString) { EXPECT_STREQ("", temperatureSensor->Tag(c)); }

TEST_F(NullTemperatureSensorTest, StateReturnsEmptyString) { EXPECT_STREQ("", temperatureSensor->State(c)); }

TEST_F(NullTemperatureSensorTest, IsNormalStateReturnsFalse) { EXPECT_FALSE(temperatureSensor->IsNormal(c)); }
