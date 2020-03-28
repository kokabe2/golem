// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_command.h"
#include "null_sensor.h"
}

class NullSensorTest : public ::testing::Test {
 protected:
  Sensor s;

  virtual void SetUp() { s = nullSensor->GetInstance(); }

  virtual void TearDown() { sensor->Delete(&s); }
};

TEST_F(NullSensorTest, SensorWatchCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), sensor->SensorWatchCommand(s, "", NULL));
}

TEST_F(NullSensorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, sensor->Id(s)); }

TEST_F(NullSensorTest, TagReturnsEmptyString) { EXPECT_STREQ("", sensor->Tag(s)); }

TEST_F(NullSensorTest, StateReturnsEmptyString) { EXPECT_STREQ("", sensor->State(s)); }

TEST_F(NullSensorTest, IsDefaultStateReturnsFalse) { EXPECT_FALSE(sensor->IsDefaultState(s)); }
