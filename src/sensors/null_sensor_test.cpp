// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "null_sensor.h"
}

class NullSensorTest : public ::testing::Test {
 protected:
  Sensor s;

  virtual void SetUp() { s = nullSensor->GetInstance(); }

  virtual void TearDown() { s->Delete(&s); }
};

TEST_F(NullSensorTest, IdReturnsNonsenseValue) { EXPECT_EQ(~0, s->Id(s)); }

TEST_F(NullSensorTest, TagReturnsEmptyString) { EXPECT_STREQ("", s->Tag(s)); }

TEST_F(NullSensorTest, StateReturnsEmptyString) { EXPECT_STREQ("", s->State(s)); }

TEST_F(NullSensorTest, IsDefaultStateReturnsFalse) { EXPECT_FALSE(s->IsDefaultState(s)); }
