// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_command.h"
#include "null_temperature_sensor.h"
}

class NullTemperatureSensorTest : public ::testing::Test {
 protected:
  TemperatureSensor ts;

  virtual void SetUp() { ts = nullTemperatureSensor->GetInstance(); }

  virtual void TearDown() { temperatureSensor->Delete(&ts); }
};

TEST_F(NullTemperatureSensorTest, SensorWatchCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), temperatureSensor->SensorWatchCommand(ts, "", NULL));
}

TEST_F(NullTemperatureSensorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, temperatureSensor->Id(ts)); }

TEST_F(NullTemperatureSensorTest, TagReturnsEmptyString) { EXPECT_STREQ("", temperatureSensor->Tag(ts)); }

TEST_F(NullTemperatureSensorTest, StateReturnsEmptyString) { EXPECT_STREQ("", temperatureSensor->State(ts)); }

TEST_F(NullTemperatureSensorTest, IsNormalStateReturnsFalse) { EXPECT_FALSE(temperatureSensor->IsNormal(ts)); }
