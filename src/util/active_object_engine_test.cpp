// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "active_object_engine.h"
#include "active_object_engine_protected.h"
#include "command_protected.h"
#include "malkt/v1/task_spy.h"
}

namespace {
int do_called_count;

void Do(Command self) { ++do_called_count; }

CommandAbstractMethodStruct kCommandSpy = {
    NULL, Do,
};
CommandStruct command_spy = {&kCommandSpy};
}  // namespace

class ActiveObjectEngineTest : public ::testing::Test {
 protected:
  ActiveObjectEngine aoe;

  virtual void SetUp() {
    taskSpy->Reset();
    aoe = activeObjectEngine->GetInstance();
  }

  virtual void TearDown() { activeObjectEngine->Delete(&aoe); }
};

TEST_F(ActiveObjectEngineTest, GetInstance) {
  activeObjectEngine->GetInstance();
  activeObjectEngine->GetInstance();
  activeObjectEngine->GetInstance();

  EXPECT_EQ(1, taskSpy->NewCalledCount());
}

TEST_F(ActiveObjectEngineTest, AddCommand) {
  activeObjectEngine->AddCommand(aoe, &command_spy);

  _activeObjectEngine->DoCommand(aoe);

  EXPECT_EQ(1, do_called_count);
}
