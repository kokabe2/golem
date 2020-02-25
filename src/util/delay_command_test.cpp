// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "delay_command.h"
#include "malkt/v1/task_spy.h"
}

TEST(DelayCommandTest, Do) {
  taskSpy->Reset();

  delayCommand->Do(10);
  delayCommand->Do(100);
  delayCommand->Do(1000);

  EXPECT_EQ(3, taskSpy->DelayCalledCount());
}
