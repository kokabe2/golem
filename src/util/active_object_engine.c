// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "active_object_engine.h"

#include <stddef.h>

#include "malkt/v1/inbox.h"
#include "malkt/v1/task.h"

typedef struct {
  void* instance;
  CommandDelegate delegate;
} CommandObjectStruct, *CommandObject;

static Task the_task;
static Inbox the_inbox;
static bool is_done;

static void ActiveObjectEngine(void) {
  the_inbox = inbox->New(1024);

  while (!is_done) {
    CommandObject co = inbox->BlockingGet(the_inbox);
    if (co != NULL) co->delegate(co->instance);
  }

  inbox->Delete(&the_inbox);
}

static void Create(void) {
  is_done = false;
  the_task = task->New(ActiveObjectEngine, 4, 1024);
  task->Run(the_task);
}

inline static void AddCommand(void* instance, CommandDelegate delegate) {
  CommandObjectStruct cos = {.instance = instance, .delegate = delegate};
  inbox->BlockingPost(the_inbox, &cos, sizeof(CommandObjectStruct));
}

static void DummyCommand(void* instance) {}

inline static void MakeTaskDone(void) {
  is_done = true;
  AddCommand(NULL, DummyCommand);
}

static void Destroy(void) {
  MakeTaskDone();
  task->Delete(&the_task);
}

static const ActiveObjectEngineMethodStruct kTheMethod = {
    .Create = Create,
    .Destroy = Destroy,
    .AddCommand = AddCommand,
};

const ActiveObjectEngineMethod activeObjectEngine = &kTheMethod;
