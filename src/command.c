// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "command.h"

static void Delete(Command *self) { (*self)->Delete(self); }

static void Do(Command self) { self->Do(self); }

static const CommandInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Do = Do,
};

const CommandInterface command = &kTheInterface;
