// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "command_script_handle_spy.h"

#include "bleu/v1/heap.h"

typedef struct {
  CommandScriptHandleInterfaceStruct impl;
  bool deleted;
  bool needs;
  bool precondition;
  bool init_called;
  int count_for_done;
  int done_callde_count;
  int idle_callde_count;
  bool postcondition;
  bool clenup_called;
  int error_code;
} CommandScriptHandleSpyStruct, *CommandScriptHandleSpy;

static void DeleteSpy(CommandScriptHandle* self) { ((CommandScriptHandleSpy)*self)->deleted = true; }

static bool NeedsExecute(CommandScriptHandle self) { return ((CommandScriptHandleSpy)self)->needs; }

static bool AssertPrecondition(CommandScriptHandle self) { return ((CommandScriptHandleSpy)self)->precondition; }

static void Init(CommandScriptHandle self) { ((CommandScriptHandleSpy)self)->init_called = true; }

static bool Done(CommandScriptHandle self) {
  return ++((CommandScriptHandleSpy)self)->done_callde_count >= ((CommandScriptHandleSpy)self)->count_for_done;
}

static void Idle(CommandScriptHandle self) { ((CommandScriptHandleSpy)self)->idle_callde_count++; }

static bool AssertPostcondition(CommandScriptHandle self) { return ((CommandScriptHandleSpy)self)->postcondition; }

static void CleanUp(CommandScriptHandle self) { ((CommandScriptHandleSpy)self)->clenup_called = true; }

static int GetErrorCode(CommandScriptHandle self) { return ((CommandScriptHandleSpy)self)->error_code; }

static CommandScriptHandle New(void) {
  CommandScriptHandleSpy self = (CommandScriptHandleSpy)heap->New(sizeof(CommandScriptHandleSpyStruct));
  self->impl.Delete = DeleteSpy;
  self->impl.NeedsExecute = NeedsExecute;
  self->impl.AssertPrecondition = AssertPrecondition;
  self->impl.Init = Init;
  self->impl.Done = Done;
  self->impl.Idle = Idle;
  self->impl.AssertPostcondition = AssertPostcondition;
  self->impl.CleanUp = CleanUp;
  self->impl.GetErrorCode = GetErrorCode;
  self->needs = true;
  self->precondition = true;
  self->postcondition = true;
  return (CommandScriptHandle)self;
}

static void Delete(CommandScriptHandle* self) { heap->Delete((void**)self); }

static bool DeleteCalled(CommandScriptHandle self) { return ((CommandScriptHandleSpy)self)->deleted; }

static void NoNeedToExecute(CommandScriptHandle self) { ((CommandScriptHandleSpy)self)->needs = false; }

static void SetPreconditionError(CommandScriptHandle self, int error_code) {
  ((CommandScriptHandleSpy)self)->error_code = error_code;
  ((CommandScriptHandleSpy)self)->precondition = false;
}

static bool InitCalled(CommandScriptHandle self) { return ((CommandScriptHandleSpy)self)->init_called; }

static void SetCountToDone(CommandScriptHandle self, int count) {
  ((CommandScriptHandleSpy)self)->count_for_done = count;
}

static int IdleCalledCount(CommandScriptHandle self) { return ((CommandScriptHandleSpy)self)->idle_callde_count; }

static void SetPostconditionError(CommandScriptHandle self, int error_code) {
  ((CommandScriptHandleSpy)self)->error_code = error_code;
  ((CommandScriptHandleSpy)self)->postcondition = false;
}

static bool CleanUpCalled(CommandScriptHandle self) { return ((CommandScriptHandleSpy)self)->clenup_called; }

static void SetErrorCode(CommandScriptHandle self, int error_code) {
  ((CommandScriptHandleSpy)self)->error_code = error_code;
}

static const CommandScriptHandleSpyMethodStruct kTheMethod = {
    .New = New,
    .Delete = Delete,
    .DeleteCalled = DeleteCalled,
    .NoNeedToExecute = NoNeedToExecute,
    .SetPreconditionError = SetPreconditionError,
    .InitCalled = InitCalled,
    .SetCountToDone = SetCountToDone,
    .IdleCalledCount = IdleCalledCount,
    .SetPostconditionError = SetPostconditionError,
    .CleanUpCalled = CleanUpCalled,
};

const CommandScriptHandleSpyMethod commandScriptHandleSpy = &kTheMethod;
