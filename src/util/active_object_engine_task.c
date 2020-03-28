// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "active_object_engine_task.h"

#include <stddef.h>

#include "active_object_engine_private.h"
#include "bleu/v1/heap.h"
#include "malkt/v1/objectizable_task.h"
#include "malkt/v1/simple_inbox.h"

typedef struct {
  ActiveObjectEngineStruct base;
  Task task;
  Inbox inbox;
  bool done;
} ActiveObjectEngineTaskStruct, *ActiveObjectEngineTask;

inline static ActiveObjectEngineTask Downcast(ActiveObjectEngine base) { return (ActiveObjectEngineTask)base; }

inline static Command BlockingGetCommand(ActiveObjectEngineTask self) {
  Command* c = inbox->BlockingGet(self->inbox);
  return c != NULL ? *c : NULL;
}

static void TaskAction(void* base) {
  ActiveObjectEngineTask self = Downcast(base);
  while (!self->done) {
    Command c = BlockingGetCommand(self);
    if (c != NULL) command->Do(c);
  }
}

inline static void AddCommand(ActiveObjectEngine self, Command c) {
  inbox->BlockingPost(Downcast(self)->inbox, &c, sizeof(Command));
}

inline static void MakeTaskDone(ActiveObjectEngine self) {
  Downcast(self)->done = true;
  AddCommand(self, NULL);
}

static void Delete(ActiveObjectEngine* self) {
  MakeTaskDone(*self);
  inbox->Delete(&Downcast(*self)->inbox);
  task->Delete(&Downcast(*self)->task);
  heap->Delete((void**)self);
}

static void Run(ActiveObjectEngine self) { task->Run(Downcast(self)->task); }

static const ActiveObjectEngineInterfaceStruct kTheInterface = {
    .Delete = Delete, .Run = Run, .AddCommand = AddCommand,
};

static ActiveObjectEngine New(void) {
  ActiveObjectEngineTask self = (ActiveObjectEngineTask)heap->New(sizeof(ActiveObjectEngineTaskStruct));
  self->base.impl = &kTheInterface;
  self->task = objectizableTask->New(TaskAction, 4, 1024, self);
  self->inbox = simpleInbox->New(1024);
  return (ActiveObjectEngine)self;
}

static const ActiveObjectEngineTaskMethodStruct kTheMethod = {
    .New = New,
};

const ActiveObjectEngineTaskMethod activeObjectEngineTask = &kTheMethod;
