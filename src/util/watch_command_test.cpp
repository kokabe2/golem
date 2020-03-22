// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "active_object_engine.h"
#include "active_object_engine_protected.h"
#include "command_protected.h"
#include "malkt/v1/uptime.h"
#include "watch_command.h"
}

namespace {
bool observed_result;
bool notified;
bool timeout_occured;

bool ObserverSpy(void) { return observed_result; }

void DoNotification(Command self) { notified = true; }

CommandAbstractMethodStruct kNotificationCommand = {
    NULL, DoNotification,
};

CommandStruct notification_ommand = {&kNotificationCommand};

void DoTimeout(Command self) { timeout_occured = true; }

CommandAbstractMethodStruct kTimeoutCommand = {
    NULL, DoTimeout,
};

CommandStruct timeout_ommand = {&kTimeoutCommand};
}  // namespace

class WatchCommandTest : public ::testing::Test {
 protected:
  ActiveObjectEngine e;
  Command c;

  virtual void SetUp() {
    observed_result = false;
    notified = false;
    timeout_occured = false;
    uptime->Set(0);
    e = activeObjectEngine->GetInstance();
    c = watchCommand->New(ObserverSpy, e, &notification_ommand);
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

TEST_F(WatchCommandTest, DoWhenObservedResultIsFalse) {
  command->Do(c);

  RunEngine(0);

  EXPECT_FALSE(notified);
}

TEST_F(WatchCommandTest, DoWhenObservedResultIsTrue) {
  command->Do(c);

  RunEngine(0);
  observed_result = true;
  RunEngine(0);

  EXPECT_TRUE(notified);
}

TEST_F(WatchCommandTest, Cancel) {
  command->Do(c);

  command->Cancel(c);

  observed_result = true;
  RunEngine(0);

  EXPECT_FALSE(notified);
}

TEST_F(WatchCommandTest, DoAfterCancelWhenObservedResultIsFalse) {
  command->Do(c);
  RunEngine(0);
  command->Cancel(c);
  RunEngine(0);
  command->Do(c);

  RunEngine(0);

  EXPECT_FALSE(notified);
}

TEST_F(WatchCommandTest, DoAfterCancelWhenObservedResultIsTrue) {
  command->Do(c);
  RunEngine(0);
  command->Cancel(c);
  RunEngine(0);
  command->Do(c);

  observed_result = true;
  RunEngine(0);

  EXPECT_TRUE(notified);
}

TEST_F(WatchCommandTest, DoWithTimeoutBeforeSetTimeElapsed) {
  watchCommand->SetTimeout(c, 1000, &timeout_ommand);
  command->Do(c);

  RunEngine(999);

  EXPECT_FALSE(timeout_occured);
}

TEST_F(WatchCommandTest, SetTimeoutThenRunAfterSetTimeElapsed) {
  watchCommand->SetTimeout(c, 1000, &timeout_ommand);
  command->Do(c);

  RunEngine(1000);

  EXPECT_TRUE(timeout_occured);
}

TEST_F(WatchCommandTest, DoWhenNotifiedBeforeTimoutOccurs) {
  watchCommand->SetTimeout(c, 1000, &timeout_ommand);
  command->Do(c);

  RunEngine(500);
  observed_result = true;
  RunEngine(1000);

  EXPECT_TRUE(notified);
  EXPECT_FALSE(timeout_occured);
}

TEST_F(WatchCommandTest, DoWhenTimoutOccursBeforeNotified) {
  watchCommand->SetTimeout(c, 1000, &timeout_ommand);
  command->Do(c);

  RunEngine(1000);
  observed_result = true;
  RunEngine(1000);

  EXPECT_FALSE(notified);
  EXPECT_TRUE(timeout_occured);
}

TEST_F(WatchCommandTest, DeleteAfterDoAndBeforeNotifiedOrTimeoutOccurs) {
  watchCommand->SetTimeout(c, 1000, &timeout_ommand);
  command->Do(c);

  command->Delete(&c);

  observed_result = true;
  RunEngine(1000);

  EXPECT_FALSE(notified);
  EXPECT_FALSE(timeout_occured);
}
