// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "golem.h"
#include "malkt/v1/task_spy.h"
}

class GolemTest : public ::testing::Test {
 protected:
  virtual void SetUp() { taskSpy->Reset(); }

  virtual void TearDown() {}
};

TEST_F(GolemTest, Create) {
  golem->Create();

  EXPECT_EQ(1, taskSpy->NewCalledCount());
  EXPECT_EQ(1, taskSpy->RunCalledCount());

  golem->Destroy();
}

TEST_F(GolemTest, Destroy) {
  golem->Create();

  golem->Destroy();

  EXPECT_EQ(1, taskSpy->DeleteCalledCount());
}
