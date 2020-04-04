// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "counting_command_stub.h"
}

class CountingCommandStubTest : public ::testing::Test {
 protected:
  Command c;

  virtual void SetUp() { c = countingCommandStub->New(); }

  virtual void TearDown() { command->Delete(&c); }
};

TEST_F(CountingCommandStubTest, CountWhenHaveNeverDo) { EXPECT_EQ(0, countingCommandStub->Count(c)); }

TEST_F(CountingCommandStubTest, Count) {
  command->Do(c);
  command->Do(c);
  command->Do(c);

  EXPECT_EQ(3, countingCommandStub->Count(c));
}
