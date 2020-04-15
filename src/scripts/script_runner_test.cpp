// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "counting_command_stub.h"
#include "script_runner.h"
#include "script_spy.h"
#include "simple_active_object_engine.h"
}

class ScriptRunnerTest : public ::testing::Test {
 protected:
  static const int kScriptSpysNum = 16;
  static const int kFailedScriptIndex = 8;
  ActiveObjectEngine e;
  Command c;
  Script script_spys[kScriptSpysNum];
  Script s;

  virtual void SetUp() {
    NewSpyScripts();
    e = simpleActiveObjectEngine->New();
    c = countingCommandStub->New();
    s = scriptRunner->New();
    script->SetEngine(s, e);
    script->SetNotificationComand(s, c);
  }

  virtual void TearDown() {
    if (s != NULL) script->Delete(&s);
    command->Delete(&c);
    activeObjectEngine->Delete(&e);
    for (int i = 0; i < kScriptSpysNum; ++i) scriptSpy->Delete(&script_spys[i]);
  }

  void NewSpyScripts() {
    for (int i = 0; i < kScriptSpysNum; ++i) {
      if (i == kFailedScriptIndex)
        script_spys[i] = scriptSpy->New("failed");
      else if (i == kScriptSpysNum - 1)
        script_spys[i] = scriptSpy->New("last");
      else
        script_spys[i] = scriptSpy->New("test");
    }
  }

  void AddAllScripts() {
    for (int i = 0; i < kScriptSpysNum; ++i) scriptRunner->AddScript(s, script_spys[i]);
  }
};

TEST_F(ScriptRunnerTest, AddOneScript) {
  scriptRunner->AddScript(s, script_spys[0]);

  script->Run(s);

  EXPECT_STREQ("test", script->GetName(s));
  EXPECT_EQ(0, script->GetErrorCode(s));
  EXPECT_TRUE(scriptSpy->RunCalled(script_spys[0]));
  EXPECT_EQ(1, countingCommandStub->Count(c));
}

TEST_F(ScriptRunnerTest, AddScripts) {
  AddAllScripts();

  script->Run(s);

  EXPECT_STREQ("last", script->GetName(s));
  EXPECT_EQ(0, script->GetErrorCode(s));
  for (int i = 0; i < kScriptSpysNum; ++i)
    EXPECT_TRUE(scriptSpy->RunCalled(script_spys[i])) << "Failure at index " << i;
  EXPECT_EQ(1, countingCommandStub->Count(c));
}

TEST_F(ScriptRunnerTest, RunWhenScriptErrorOccurs) {
  scriptSpy->SetErrorCode(script_spys[kFailedScriptIndex], 1234);
  AddAllScripts();

  script->Run(s);

  EXPECT_STREQ("failed", script->GetName(s));
  EXPECT_EQ(1234, script->GetErrorCode(s));
  for (int i = 0; i <= kFailedScriptIndex; ++i)
    EXPECT_TRUE(scriptSpy->RunCalled(script_spys[i])) << "Failure at index " << i;
  for (int i = kFailedScriptIndex + 1; i < kScriptSpysNum; ++i)
    EXPECT_FALSE(scriptSpy->RunCalled(script_spys[i])) << "Failure at index " << i;
  EXPECT_EQ(1, countingCommandStub->Count(c));
}

TEST_F(ScriptRunnerTest, RunWhenScriptErrorOccursInLastScript) {
  scriptSpy->SetErrorCode(script_spys[kScriptSpysNum - 1], 1234);
  AddAllScripts();

  script->Run(s);

  EXPECT_STREQ("last", script->GetName(s));
  EXPECT_EQ(1234, script->GetErrorCode(s));
  for (int i = 0; i <= kScriptSpysNum; ++i)
    EXPECT_TRUE(scriptSpy->RunCalled(script_spys[i])) << "Failure at index " << i;
  EXPECT_EQ(1, countingCommandStub->Count(c));
}

TEST_F(ScriptRunnerTest, DeleteDestroysAllScriptsAdded) {
  AddAllScripts();

  script->Delete(&s);

  for (int i = 0; i < kScriptSpysNum; ++i)
    EXPECT_TRUE(scriptSpy->DeleteCalled(script_spys[i])) << "Failure at index " << i;
}
