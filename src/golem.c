// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "golem.h"

#include "malkt/v1/task.h"
#include "util/scheduled_process_manager.h"

static Task the_task;
static int interval_in_milliseconds;

static void GolemAction(void) {
  for (;; task->Delay(interval_in_milliseconds)) scheduledProcessManager->Kick();
}

static void Create(void) {
  scheduledProcessManager->Create();
  the_task = task->New(GolemAction, 4, 1024);
  task->Run(the_task);
  interval_in_milliseconds = 10;
}

static void Destroy(void) {
  task->Delete(&the_task);
  scheduledProcessManager->Destroy();
}

static void SetWakeUpInterval(int milliseconds) { interval_in_milliseconds = milliseconds; }

static void AddBackgroundProcess(GolemBackgroundProcess process, int interval_in_milliseconds) {
  scheduledProcessManager->Add(process, interval_in_milliseconds);
}

static const GolemMethodStruct kTheMethod = {
    .Create = Create,
    .Destroy = Destroy,
    .SetWakeUpInterval = SetWakeUpInterval,
    .AddBackgroundProcess = AddBackgroundProcess,
};

const GolemMethod golem = &kTheMethod;
