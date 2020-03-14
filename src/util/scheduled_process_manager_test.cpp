// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "malkt/v1/uptime.h"
#include "scheduled_process_manager.h"
}

namespace {
int called_count;

void ProcessSpy(void) { ++called_count; }
}  // namespace

class ScheduledProcessManagerTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
    called_count = 0;
    uptime->Set(0);
    scheduledProcessManager->Create();
  }

  virtual void TearDown() { scheduledProcessManager->Destroy(); }

  void AddThreeProcesses() {
    scheduledProcessManager->Add(ProcessSpy, 10);
    scheduledProcessManager->Add(ProcessSpy, 100);
    scheduledProcessManager->Add(ProcessSpy, 1000);
  }
};

TEST_F(ScheduledProcessManagerTest, KickOneProcess) {
  AddThreeProcesses();
  uptime->Set(50);

  scheduledProcessManager->Kick();

  EXPECT_EQ(1, called_count);
}

TEST_F(ScheduledProcessManagerTest, KickThreeProcess) {
  AddThreeProcesses();
  uptime->Set(1000);

  scheduledProcessManager->Kick();

  EXPECT_EQ(3, called_count);
}

TEST_F(ScheduledProcessManagerTest, KickNoProcess) {
  AddThreeProcesses();

  scheduledProcessManager->Kick();

  EXPECT_EQ(0, called_count);
}

TEST_F(ScheduledProcessManagerTest, KickWhenNoProcessHasNoEffect) { scheduledProcessManager->Kick(); }
