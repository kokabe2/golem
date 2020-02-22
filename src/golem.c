// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "golem.h"

#include <stddef.h>

#include "malkt/v1/task.h"

static Task the_task = NULL;

static void GolemAction(void) {
  for (;; task->Delay(10)) continue;
}
static void Create(void) {
  if (the_task) return;
  the_task = task->New(GolemAction, 4, 1024);
  task->Run(the_task);
}
static void Destroy(void) { task->Delete(&the_task); }
static const GolemMethodStruct kTheMethod = {
    .Create = Create, .Destroy = Destroy,
};
const GolemMethod golem = &kTheMethod;
