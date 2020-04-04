// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "error_command.h"
}

namespace {
const char* given_message;
int given_error;
int given_parameter;

void NotifySpy(const char* message, int error, int parameter) {
  given_message = message;
  given_error = error;
  given_parameter = parameter;
}
}  // namespace

class ErrorCommandTest : public ::testing::Test {
 protected:
  Command c;

  virtual void SetUp() {
    given_message = "";
    given_error = ~0;
    given_parameter = ~0;
    c = errorCommand->New(NotifySpy);
  }

  virtual void TearDown() { command->Delete(&c); }
};

TEST_F(ErrorCommandTest, Do) {
  errorCommand->SetErrorInfo(c, "Test", -128, 10);

  command->Do(c);

  EXPECT_STREQ(given_message, "Test");
  EXPECT_EQ(given_error, -128);
  EXPECT_EQ(given_parameter, 10);
}
