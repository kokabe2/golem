// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "active_object_engine.h"

#include <stddef.h>

#include "active_object_engine_protected.h"
#include "malkt/v1/inbox.h"
#include "malkt/v1/task.h"

typedef struct ActiveObjectEngineStruct {
  Task task;
  Inbox inbox;
  bool is_done;
} ActiveObjectEngineStruct;

static ActiveObjectEngineStruct the_singleton;
static ActiveObjectEngine the_instance = NULL;

inline static Command BlockingGetCommand(ActiveObjectEngine self) {
  Command* c = inbox->BlockingGet(self->inbox);
  return c != NULL ? *c : NULL;
}

inline static void DoCommand(ActiveObjectEngine self) {
  Command c = BlockingGetCommand(self);
  if (c != NULL) command->Do(c);
}

static const ActiveObjectEngineProtectedMethodStruct kProtectedMethod = {
    .DoCommand = DoCommand,
};

const ActiveObjectEngineProtectedMethod _activeObjectEngine = &kProtectedMethod;

static void TaskAction(void) {
  while (!the_instance->is_done) DoCommand(the_instance);
}

static ActiveObjectEngine New(void) {
  the_singleton.is_done = false;
  the_singleton.task = task->New(TaskAction, 4, 1024);
  the_singleton.inbox = inbox->New(1024);
  return &the_singleton;
}

static ActiveObjectEngine GetInstance(void) {
  if (the_instance == NULL) the_instance = New();
  return the_instance;
}

inline static void AddCommand(ActiveObjectEngine self, Command c) {
  inbox->BlockingPost(self->inbox, &c, sizeof(Command));
}

inline static void MakeTaskDone(ActiveObjectEngine self) {
  self->is_done = true;
  AddCommand(self, NULL);
}

static void Delete(ActiveObjectEngine* self) {
  MakeTaskDone(*self);
  inbox->Delete(&(*self)->inbox);
  task->Delete(&(*self)->task);
  the_instance = NULL;
}

static void Run(ActiveObjectEngine self) { task->Run(self->task); }

static const ActiveObjectEngineMethodStruct kTheMethod = {
    .GetInstance = GetInstance,
    .Delete = Delete,
    .Run = Run,
    .AddCommand = AddCommand,
};

const ActiveObjectEngineMethod activeObjectEngine = &kTheMethod;
