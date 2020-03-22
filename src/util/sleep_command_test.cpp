// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "active_object_engine.h"
#include "active_object_engine_protected.h"
#include "command_protected.h"
#include "malkt/v1/uptime.h"
#include "sleep_command.h"
}

namespace {
bool command_executed;

void Do(Command self) { command_executed = true; }

CommandAbstractMethodStruct kWakeupCommand = {
    NULL, Do,
};

CommandStruct wakeup_command = {&kWakeupCommand};
}  // namespace

class SleepCommandTest : public ::testing::Test {
 protected:
  ActiveObjectEngine e;
  Command c;

  virtual void SetUp() {
    command_executed = false;
    uptime->Set(0);
    e = activeObjectEngine->GetInstance();
    c = sleepCommand->New(1000, e, &wakeup_command);
  }

  virtual void TearDown() {
    if (c != NULL) command->Delete(&c);
    activeObjectEngine->Delete(&e);
  }

  void RunEngine(uint64_t current_time) {
    uptime->Set(current_time);
    for (int i = 0; i < 10; ++i) _activeObjectEngine->DoCommand(e);  // Use DoCommand() instead of Run() for test.
  }
};

TEST_F(SleepCommandTest, DoWhenSleepTimeNotElapsed) {
  command->Do(c);

  RunEngine(999);

  EXPECT_FALSE(command_executed);
}

TEST_F(SleepCommandTest, DoWhenSleepTimeElapsed) {
  command->Do(c);

  RunEngine(1000);

  EXPECT_TRUE(command_executed);
}

TEST_F(SleepCommandTest, Cancel) {
  command->Do(c);

  command->Cancel(c);

  RunEngine(1000);

  EXPECT_FALSE(command_executed);
}

TEST_F(SleepCommandTest, DoAfterCancelWhenSleepTimeNotElapsed) {
  command->Do(c);
  RunEngine(500);
  command->Cancel(c);
  RunEngine(500);

  command->Do(c);

  RunEngine(1000);

  EXPECT_FALSE(command_executed);
}

TEST_F(SleepCommandTest, DoAfterCancelWhenSleepTimeElapsed) {
  command->Do(c);
  RunEngine(500);
  command->Cancel(c);
  RunEngine(500);

  command->Do(c);

  RunEngine(1500);

  EXPECT_TRUE(command_executed);
}

TEST_F(SleepCommandTest, Get) { EXPECT_EQ(1000, sleepCommand->GetSleepTime(c)); }

TEST_F(SleepCommandTest, Set) {
  sleepCommand->SetSleepTime(c, 100);

  EXPECT_EQ(100, sleepCommand->GetSleepTime(c));
}

TEST_F(SleepCommandTest, DeleteAfterDoAndBeforeWakeUp) {
  command->Do(c);

  command->Delete(&c);

  RunEngine(1000);

  EXPECT_FALSE(command_executed);
}
