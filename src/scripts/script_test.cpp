// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "counting_command_stub.h"
#include "script_spy.h"
#include "simple_active_object_engine.h"
}

class ScriptTest : public ::testing::Test {
 protected:
  ActiveObjectEngine e;
  Command c;
  Script s;

  virtual void SetUp() {
    e = simpleActiveObjectEngine->New();
    c = countingCommandStub->New();
    s = scriptSpy->New("test");
    script->SetEngine(s, e);
    script->SetNotificationComand(s, c);
  }

  virtual void TearDown() {
    scriptSpy->Delete(&s);
    command->Delete(&c);
    activeObjectEngine->Delete(&e);
  }
};

TEST_F(ScriptTest, Delete) {
  script->Delete(&s);

  EXPECT_TRUE(scriptSpy->DeleteCalled(s));
}

TEST_F(ScriptTest, Run) {
  script->Run(s);

  EXPECT_TRUE(scriptSpy->RunCalled(s));
}

TEST_F(ScriptTest, SetEngine) { EXPECT_EQ(e, scriptSpy->GetEngine(s)); }

TEST_F(ScriptTest, SetNotificationCommand) { EXPECT_EQ(c, scriptSpy->GetNotificationCommand(s)); }

TEST_F(ScriptTest, GetName) { EXPECT_STREQ("test", script->GetName(s)); }

TEST_F(ScriptTest, GetErrorCode) {
  scriptSpy->SetErrorCode(s, 1234);

  EXPECT_EQ(1234, script->GetErrorCode(s));
}

TEST_F(ScriptTest, HasError) {
  scriptSpy->SetErrorCode(s, 1234);

  EXPECT_TRUE(script->HasError(s));
}
