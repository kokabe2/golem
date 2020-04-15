// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "script_runner.h"

#include "bleu/v1/heap.h"
#include "bleu/v1/list.h"
#include "script_protected.h"

typedef struct {
  ScriptStruct base;
  List scripts;
  int count;
} ScriptRunnerStruct, *ScriptRunner;

inline static void Delete(Command* base) {
  ScriptRunner self = (ScriptRunner)*base;
  list->Delete(&self->scripts);
  heap->Delete((void**)base);
}

inline static void SetUpNextScript(ScriptRunner self) {
  Script s = list->Get(self->scripts, self->count++);
  script->SetEngine(s, self->base.engine);
  script->SetNotificationComand(s, (Command)self);
  activeObjectEngine->AddCommand(self->base.engine, (Command)s);
}

inline static bool AllScriptsDone(ScriptRunner self) { return self->count == list->Count(self->scripts); }

inline static Script GetLastScript(ScriptRunner self) { return list->Get(self->scripts, self->count - 1); }

inline static bool HasErrorWithLastScript(ScriptRunner self) {
  Script s = GetLastScript(self);
  return script->HasError(s);
}

inline static void CleanUp(ScriptRunner self) {
  Script s = GetLastScript(self);
  self->base.name = script->GetName(s);
  self->base.error_code = script->GetErrorCode(s);
  activeObjectEngine->AddCommand(self->base.engine, self->base.notification_command);
}

inline static void Run(ScriptRunner self) {
  if (self->count == 0) {
    SetUpNextScript(self);
    activeObjectEngine->Run(self->base.engine);
  } else if (AllScriptsDone(self) || HasErrorWithLastScript(self)) {
    CleanUp(self);
  } else {
    SetUpNextScript(self);
  }
}

static void Do(Command self) { Run((ScriptRunner)self); }

static void ScriptDeleter(void** self) { script->Delete((Script*)self); }

static Script New(void) {
  ScriptRunner self = heap->New(sizeof(ScriptRunnerStruct));
  self->base.impl.Delete = Delete;
  self->base.impl.Do = Do;
  self->scripts = list->New();
  list->SetItemDeleter(self->scripts, ScriptDeleter);
  return (Script)self;
}

static void AddScript(Script self, Script script) { list->Add(((ScriptRunner)self)->scripts, script); }

static const ScriptRunnerMethodStruct kTheMethod = {
    .New = New,
    .AddScript = AddScript,
};

const ScriptRunnerMethod scriptRunner = &kTheMethod;
