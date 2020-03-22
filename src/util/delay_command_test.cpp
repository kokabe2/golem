// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "delay_command.h"
#include "malkt/v1/task_spy.h"
}

class DelayCommandTest : public ::testing::Test {
 protected:
  Command c;

  virtual void SetUp() {
    taskSpy->Reset();
    c = delayCommand->New(10);
  }

  virtual void TearDown() { command->Delete(&c); }
};

TEST_F(DelayCommandTest, DoExecuteTaskDelay) {
  command->Do(c);
  command->Do(c);
  command->Do(c);

  EXPECT_EQ(3, taskSpy->DelayCalledCount());
}

TEST_F(DelayCommandTest, Get) { EXPECT_EQ(10, delayCommand->GetDelayTime(c)); }

TEST_F(DelayCommandTest, Set) {
  delayCommand->SetDelayTime(c, 100);

  EXPECT_EQ(100, delayCommand->GetDelayTime(c));
}
