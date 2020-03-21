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
    command->Delete(&c);
    activeObjectEngine->Delete(&e);
  }

  void RunEngine(uint64_t current_time) {
    uptime->Set(current_time);
    _activeObjectEngine->DoCommand(e);  // Use DoCommand() instead of Run() for test.
  }
};

TEST_F(SleepCommandTest, Do) {
  command->Do(c);

  EXPECT_FALSE(command_executed);
}

TEST_F(SleepCommandTest, DoThenRunFirstTime) {
  command->Do(c);

  RunEngine(1500);

  EXPECT_FALSE(command_executed);
}

TEST_F(SleepCommandTest, DoThenRunBeforeSleepTimeElapsed) {
  command->Do(c);

  RunEngine(999);
  RunEngine(1000);

  EXPECT_FALSE(command_executed);
}

TEST_F(SleepCommandTest, DoThenRunAfterSleepTimeElapsed) {
  command->Do(c);

  RunEngine(1000);
  RunEngine(1000);

  EXPECT_TRUE(command_executed);
}

TEST_F(SleepCommandTest, DoAfterSleepTimeElapsed) {
  command->Do(c);
  RunEngine(1000);
  RunEngine(1000);
  command_executed = false;

  command->Do(c);

  RunEngine(1000);

  EXPECT_TRUE(command_executed);
}

TEST_F(SleepCommandTest, Get) { EXPECT_EQ(1000, sleepCommand->GetSleepTime(c)); }

TEST_F(SleepCommandTest, Set) {
  sleepCommand->SetSleepTime(c, 100);

  EXPECT_EQ(100, sleepCommand->GetSleepTime(c));
}
