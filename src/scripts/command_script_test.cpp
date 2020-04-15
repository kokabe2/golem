// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "command_script.h"
#include "command_script_handle_spy.h"
#include "counting_command_stub.h"
#include "simple_active_object_engine.h"
}

class CommandScriptTest : public ::testing::Test {
 protected:
  ActiveObjectEngine e;
  Command c;
  CommandScriptHandle handle_spy;
  Script s;

  virtual void SetUp() {
    handle_spy = commandScriptHandleSpy->New();
    e = simpleActiveObjectEngine->New();
    c = countingCommandStub->New();
    s = commandScript->New("test", handle_spy);
    script->SetEngine(s, e);
    script->SetNotificationComand(s, c);
  }

  virtual void TearDown() {
    if (s != NULL) script->Delete(&s);
    command->Delete(&c);
    activeObjectEngine->Delete(&e);
    commandScriptHandleSpy->Delete(&handle_spy);
  }
};

TEST_F(CommandScriptTest, Run) {
  script->Run(s);

  EXPECT_STREQ("test", script->GetName(s));
  EXPECT_EQ(0, script->GetErrorCode(s));
  EXPECT_EQ(1, countingCommandStub->Count(c));
}

TEST_F(CommandScriptTest, RunWhenNoNeedToExecute) {
  commandScriptHandleSpy->NoNeedToExecute(handle_spy);

  script->Run(s);

  EXPECT_EQ(0, script->GetErrorCode(s));
  EXPECT_FALSE(commandScriptHandleSpy->InitCalled(handle_spy));
  EXPECT_EQ(0, commandScriptHandleSpy->IdleCalledCount(handle_spy));
  EXPECT_FALSE(commandScriptHandleSpy->CleanUpCalled(handle_spy));
}

TEST_F(CommandScriptTest, RunWhenPreconditionAssertionFailed) {
  commandScriptHandleSpy->SetPreconditionError(handle_spy, 1234);

  script->Run(s);

  EXPECT_EQ(1234, script->GetErrorCode(s));
  EXPECT_FALSE(commandScriptHandleSpy->InitCalled(handle_spy));
  EXPECT_EQ(0, commandScriptHandleSpy->IdleCalledCount(handle_spy));
  EXPECT_FALSE(commandScriptHandleSpy->CleanUpCalled(handle_spy));
}

TEST_F(CommandScriptTest, RunWhenPostconditionAssertionFailed) {
  commandScriptHandleSpy->SetPostconditionError(handle_spy, 1234);

  script->Run(s);

  EXPECT_EQ(1234, script->GetErrorCode(s));
  EXPECT_TRUE(commandScriptHandleSpy->InitCalled(handle_spy));
  EXPECT_EQ(0, commandScriptHandleSpy->IdleCalledCount(handle_spy));
  EXPECT_TRUE(commandScriptHandleSpy->CleanUpCalled(handle_spy));
}

TEST_F(CommandScriptTest, RunWhenTakesSomeTimeToDone) {
  commandScriptHandleSpy->SetCountToDone(handle_spy, 10);

  script->Run(s);

  EXPECT_EQ(0, script->GetErrorCode(s));
  EXPECT_TRUE(commandScriptHandleSpy->InitCalled(handle_spy));
  EXPECT_EQ(10 - 1, commandScriptHandleSpy->IdleCalledCount(handle_spy));
  EXPECT_TRUE(commandScriptHandleSpy->CleanUpCalled(handle_spy));
}

TEST_F(CommandScriptTest, DeleteDestroysCommandScriptHandle) {
  script->Delete(&s);

  EXPECT_TRUE(commandScriptHandleSpy->DeleteCalled(handle_spy));
}
