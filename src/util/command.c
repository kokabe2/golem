// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "command.h"

#include "command_protected.h"

static void Delete(Command *self) { (*self)->impl->Delete(self); }

static void Do(Command self) { self->impl->Do(self); }

static void Undo(Command self) { self->impl->Undo(self); }

static void Redo(Command self) { self->impl->Redo(self); }

static const CommandAbstractMethodStruct kTheMethod = {
    .Delete = Delete,
    .Do = Do,
    .Undo = Undo,
    .Redo = Redo,
};

const CommandAbstractMethod command = &kTheMethod;
