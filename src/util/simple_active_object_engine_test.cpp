// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "counting_command_stub.h"
#include "simple_active_object_engine.h"
}

class SimpleActiveObjectEngineTest : public ::testing::Test {
 protected:
  Command c;
  ActiveObjectEngine e;

  virtual void SetUp() {
    c = countingCommandStub->New();
    e = simpleActiveObjectEngine->New();
  }

  virtual void TearDown() {
    activeObjectEngine->Delete(&e);
    command->Delete(&c);
  }
};

TEST_F(SimpleActiveObjectEngineTest, Run) {
  activeObjectEngine->AddCommand(e, c);

  activeObjectEngine->Run(e);

  EXPECT_EQ(1, countingCommandStub->Count(c));
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

  EXPECT_EQ(3, countingCommandStub->Count(c));
}
