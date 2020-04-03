// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_command.h"
#include "null_sensor.h"
}

class NullSensorTest : public ::testing::Test {
 protected:
  Component c;

  virtual void SetUp() { c = nullSensor->GetInstance(); }

  virtual void TearDown() { sensor->Delete(&c); }
};

TEST_F(NullSensorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, sensor->Id(c)); }

TEST_F(NullSensorTest, TagReturnsEmptyString) { EXPECT_STREQ("", sensor->Tag(c)); }

TEST_F(NullSensorTest, SensorWatchCommandReturnsNullCommand) {
  EXPECT_EQ(nullCommand->GetInstance(), sensor->SensorWatchCommand(c, "", NULL));
}

TEST_F(NullSensorTest, StateReturnsEmptyString) { EXPECT_STREQ("", sensor->State(c)); }

TEST_F(NullSensorTest, IsDefaultStateReturnsFalse) { EXPECT_FALSE(sensor->IsDefaultState(c)); }
