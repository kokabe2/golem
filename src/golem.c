// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "golem.h"

#include "malkt/v1/task.h"

static Task the_task;
static int interval_in_milliseconds = 10;

static void GolemAction(void) {
  for (;; task->Delay(interval_in_milliseconds)) continue;
}

static void Create(void) {
  the_task = task->New(GolemAction, 4, 1024);
  task->Run(the_task);
}

static void Destroy(void) { task->Delete(&the_task); }

static void SetWakeUpInterval(int milliseconds) { interval_in_milliseconds = milliseconds; }

static const GolemMethodStruct kTheMethod = {
    .Create = Create,
    .Destroy = Destroy,
    .SetWakeUpInterval = SetWakeUpInterval,
};

const GolemMethod golem = &kTheMethod;
