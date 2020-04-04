// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "../util/time_unit_stub.h"
#include "command_private.h"
#include "simple_active_object_engine.h"
#include "sleep_command.h"
}

namespace {
bool was_ran;

void Do(Command self) { was_ran = true; }

CommandInterfaceStruct kSpyInterface = {
    NULL, Do,
};

CommandStruct command_spy = {&kSpyInterface};
}  // namespace

class SleepCommandTest : public ::testing::Test {
 protected:
  ActiveObjectEngine e;
  Command c;

  virtual void SetUp() {
    was_ran = false;
    timeUnitStub->Reset(0, 20);
    e = simpleActiveObjectEngine->New();
    c = sleepCommand->New(100, e, &command_spy);
  }

  virtual void TearDown() {
    command->Delete(&c);
    activeObjectEngine->Delete(&e);
  }
};

TEST_F(SleepCommandTest, Do) {
  command->Do(c);

  activeObjectEngine->Run(e);

  EXPECT_TRUE(was_ran);
  int64_t t = timeUnit->Now(timeUnit->Millisecond);
  EXPECT_GE(t, 100);
  EXPECT_LE(t, 120);
}
