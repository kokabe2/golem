// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "command_script.h"

#include "bleu/v1/heap.h"
#include "script_protected.h"

typedef struct {
  ScriptStruct base;
  CommandScriptHandle handle;
  bool started;
} CommandScriptStruct, *CommandScript;

static void Delete(Command* base) {
  CommandScript self = (CommandScript)*base;
  commandScriptHandle->Delete(&self->handle);
  heap->Delete((void**)base);
}

inline static void Run(CommandScript self) {
  if (!self->started) {
    if (!commandScriptHandle->NeedsExecute(self->handle)) {
      activeObjectEngine->AddCommand(self->base.engine, self->base.notification_command);
    } else if (!commandScriptHandle->AssertPrecondition(self->handle)) {
      self->base.error_code = commandScriptHandle->GetErrorCode(self->handle);
      activeObjectEngine->AddCommand(self->base.engine, self->base.notification_command);
    } else {
      self->started = true;
      commandScriptHandle->Init(self->handle);
      activeObjectEngine->AddCommand(self->base.engine, (Command)self);
      activeObjectEngine->Run(self->base.engine);
    }
  } else if (commandScriptHandle->Done(self->handle)) {
    if (!commandScriptHandle->AssertPostcondition(self->handle))
      self->base.error_code = commandScriptHandle->GetErrorCode(self->handle);
    commandScriptHandle->CleanUp(self->handle);
    activeObjectEngine->AddCommand(self->base.engine, self->base.notification_command);
  } else {
    commandScriptHandle->Idle(self->handle);
    activeObjectEngine->AddCommand(self->base.engine, (Command)self);
  }
}

static void Do(Command self) { Run((CommandScript)self); }

static Script New(const char* name, CommandScriptHandle handle) {
  CommandScript self = heap->New(sizeof(CommandScriptStruct));
  self->base.impl.Delete = Delete;
  self->base.impl.Do = Do;
  self->base.name = name;
  self->handle = handle;
  return (Script)self;
}

static const CommandScriptMethodStruct kTheMethod = {
    .New = New,
};

const CommandScriptMethod commandScript = &kTheMethod;
