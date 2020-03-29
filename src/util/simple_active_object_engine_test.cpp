// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "command_private.h"
#include "simple_active_object_engine.h"
}

namespace {
int called_count;

void Do(Command self) { ++called_count; }

CommandInterfaceStruct kSpyInterface = {
    NULL, Do,
};

CommandStruct command_spy = {&kSpyInterface};
}  // namespace

class SimpleActiveObjectEngineTest : public ::testing::Test {
 protected:
  Command c;
  ActiveObjectEngine e;

  virtual void SetUp() {
    called_count = 0;
    c = &command_spy;
    e = simpleActiveObjectEngine->New();
  }

  virtual void TearDown() { activeObjectEngine->Delete(&e); }
};

TEST_F(SimpleActiveObjectEngineTest, Run) {
  activeObjectEngine->AddCommand(e, c);

  activeObjectEngine->Run(e);

  EXPECT_EQ(1, called_count);
}

TEST_F(SimpleActiveObjectEngineTest, RunWhenNoCommandAddedHasNoEffect) {
  activeObjectEngine->Run(e);

  SUCCEED();
}

TEST_F(SimpleActiveObjectEngineTest, AddCommandMultipleTimes) {
  activeObjectEngine->AddCommand(e, c);
  activeObjectEngine->AddCommand(e, c);
  activeObjectEngine->AddCommand(e, c);

  activeObjectEngine->Run(e);

  EXPECT_EQ(3, called_count);
}
