// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "command_script_handle.h"

static void Delete(CommandScriptHandle* self) { (*self)->Delete(self); }

static bool NeedsExecute(CommandScriptHandle self) { return self->NeedsExecute(self); }

static bool AssertPrecondition(CommandScriptHandle self) { return self->AssertPrecondition(self); }

static void Init(CommandScriptHandle self) { self->Init(self); }

static bool Done(CommandScriptHandle self) { return self->Done(self); }

static void Idle(CommandScriptHandle self) { self->Idle(self); }

static bool AssertPostcondition(CommandScriptHandle self) { return self->AssertPostcondition(self); }

static void CleanUp(CommandScriptHandle self) { self->CleanUp(self); }

static int GetErrorCode(CommandScriptHandle self) { return self->GetErrorCode(self); }

static const CommandScriptHandleInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .NeedsExecute = NeedsExecute,
    .AssertPrecondition = AssertPrecondition,
    .Init = Init,
    .Done = Done,
    .Idle = Idle,
    .AssertPostcondition = AssertPostcondition,
    .CleanUp = CleanUp,
    .GetErrorCode = GetErrorCode,
};

const CommandScriptHandleInterface commandScriptHandle = &kTheInterface;
