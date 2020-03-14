// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "gtest/gtest.h"

extern "C" {
#include "malkt/v1/one_shot_timer_spy.h"
#include "malkt/v1/timer_spy.h"
#include "one_shot_timer_manager.h"
}

namespace {
void DummyHandler(void) {}
}  // namespace

class OneShotTimerManagerTest : public ::testing::Test {
 protected:
  bool is_destroyed;

  virtual void SetUp() {
    is_destroyed = false;
    timerSpy->Reset();
    oneShotTimerSpy->Reset();
    oneShotTimerManager->Create();
  }

  virtual void TearDown() { DestroyOneShotTimerManager(); }

  void AddThreeTimers() {
    oneShotTimerManager->Add(DummyHandler, 10);
    oneShotTimerManager->Add(DummyHandler, 100);
    oneShotTimerManager->Add(DummyHandler, 1000);
  }

  void DestroyOneShotTimerManager() {
    if (!is_destroyed) {
      oneShotTimerManager->Destroy();
      is_destroyed = true;
    }
  }
};

TEST_F(OneShotTimerManagerTest, ConditionAfterCreate) {
  EXPECT_EQ(16, oneShotTimerManager->GetMaxInspectionsOnceEveryClean());
}

TEST_F(OneShotTimerManagerTest, Add) {
  AddThreeTimers();

  EXPECT_EQ(3, oneShotTimerSpy->NewCalledCount());
}

TEST_F(OneShotTimerManagerTest, Clean) {
  AddThreeTimers();
  oneShotTimerSpy->Run(0);
  oneShotTimerSpy->Run(2);

  oneShotTimerManager->Clean();

  EXPECT_EQ(2, timerSpy->DeleteCalledCount());
}

TEST_F(OneShotTimerManagerTest, CleanWhenNoTimerHasDone) {
  AddThreeTimers();

  oneShotTimerManager->Clean();

  EXPECT_EQ(0, timerSpy->DeleteCalledCount());
}

TEST_F(OneShotTimerManagerTest, SetMaxInspectionsOnceEveryClean) {
  oneShotTimerManager->SetMaxInspectionsOnceEveryClean(2);

  EXPECT_EQ(2, oneShotTimerManager->GetMaxInspectionsOnceEveryClean());
}

TEST_F(OneShotTimerManagerTest, CleanWhenTimerHadDoneButNotInspected) {
  AddThreeTimers();
  oneShotTimerManager->SetMaxInspectionsOnceEveryClean(2);
  oneShotTimerSpy->Run(2);

  oneShotTimerManager->Clean();

  EXPECT_EQ(0, timerSpy->DeleteCalledCount());
}

TEST_F(OneShotTimerManagerTest, Destroy) {
  AddThreeTimers();
  oneShotTimerSpy->Run(2);
  oneShotTimerManager->Clean();

  DestroyOneShotTimerManager();

  EXPECT_EQ(3, timerSpy->DeleteCalledCount());
}

TEST_F(OneShotTimerManagerTest, SampleTransaction) {
  AddThreeTimers();

  oneShotTimerSpy->Run(1);
  oneShotTimerManager->Clean();
  EXPECT_EQ(1, timerSpy->DeleteCalledCount());

  oneShotTimerManager->Clean();
  EXPECT_EQ(1, timerSpy->DeleteCalledCount());

  oneShotTimerSpy->Run(0);
  oneShotTimerSpy->Run(2);
  oneShotTimerManager->Clean();
  EXPECT_EQ(3, timerSpy->DeleteCalledCount());

  oneShotTimerManager->Clean();
  EXPECT_EQ(3, timerSpy->DeleteCalledCount());
}
