// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "malkt/v1/task_spy.h"
#include "watch_command.h"
}

namespace {
int watch_count;
int count_for_true;

bool WatchSpy(void) {
  ++watch_count;
  return watch_count >= count_for_true;
}
}

class WatchCommandTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    watch_count = 0;
    count_for_true = 0;
    taskSpy->Reset();
  }

  virtual void TearDown() {}
};

TEST_F(WatchCommandTest, DoOnce) {
  EXPECT_TRUE(watchCommand->Do(WatchSpy, 0, 0, 0));  // Period doesn't matter.
  EXPECT_EQ(1, taskSpy->DelayCalledCount());
  EXPECT_EQ(1, watch_count);
}

TEST_F(WatchCommandTest, DoInSimpleCase) {
  count_for_true = 2;

  EXPECT_TRUE(watchCommand->Do(WatchSpy, 1, 1, 1));
  EXPECT_EQ(2, taskSpy->DelayCalledCount());
  EXPECT_EQ(2, watch_count);
}

TEST_F(WatchCommandTest, DoInSimpleTimeout) {
  count_for_true = 3;

  EXPECT_FALSE(watchCommand->Do(WatchSpy, 1, 1, 1));
  EXPECT_EQ(2, taskSpy->DelayCalledCount());
  EXPECT_EQ(2, watch_count);
}

TEST_F(WatchCommandTest, Do) {
  count_for_true = 101;

  EXPECT_TRUE(watchCommand->Do(WatchSpy, 10, 1, 100));
  EXPECT_EQ(101, taskSpy->DelayCalledCount());
  EXPECT_EQ(101, watch_count);
}

TEST_F(WatchCommandTest, DoThenTimeout) {
  count_for_true = 52;

  EXPECT_FALSE(watchCommand->Do(WatchSpy, 1, 2, 100));
  EXPECT_EQ(51, taskSpy->DelayCalledCount());
  EXPECT_EQ(51, watch_count);
}

TEST_F(WatchCommandTest, DoWithInvalidArgument) {
  EXPECT_FALSE(watchCommand->Do(WatchSpy, 10, 0, 10));
  EXPECT_FALSE(watchCommand->Do(WatchSpy, 10, -1, 10));
  EXPECT_FALSE(watchCommand->Do(WatchSpy, 10, 10, -1));
  EXPECT_EQ(0, taskSpy->DelayCalledCount());
  EXPECT_EQ(0, watch_count);
}
