// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "script_spy.h"

#include "bleu/v1/heap.h"
#include "script_protected.h"

typedef struct {
  ScriptStruct base;
  bool deleted;
  bool done;
} ScriptSpyStruct, *ScriptSpy;

static void DeleteSpy(Command* self) { ((ScriptSpy)*self)->deleted = true; }

static void DoSpy(Command base) {
  ScriptSpy self = (ScriptSpy)base;
  self->done = true;
  activeObjectEngine->AddCommand(self->base.engine, self->base.notification_command);
}

static Script New(const char* name) {
  ScriptSpy self = (ScriptSpy)heap->New(sizeof(ScriptSpyStruct));
  self->base.impl.Delete = DeleteSpy;
  self->base.impl.Do = DoSpy;
  self->base.name = name;
  return (Script)self;
}

static void Delete(Script* self) { heap->Delete((void**)self); }

static bool DeleteCalled(Script self) { return ((ScriptSpy)self)->deleted; }

static bool RunCalled(Script self) { return ((ScriptSpy)self)->done; }

static ActiveObjectEngine GetEngine(Script self) { return self->engine; }

static Command GetNotificationCommand(Script self) { return self->notification_command; }

static void SetErrorCode(Script self, int error_code) { self->error_code = error_code; }

static const ScriptSpyMethodStruct kTheMethod = {
    .New = New,
    .Delete = Delete,
    .DeleteCalled = DeleteCalled,
    .RunCalled = RunCalled,
    .GetEngine = GetEngine,
    .GetNotificationCommand = GetNotificationCommand,
    .SetErrorCode = SetErrorCode,
};

const ScriptSpyMethod scriptSpy = &kTheMethod;
