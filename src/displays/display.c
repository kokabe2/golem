// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "display.h"

static void Delete(Component* self) { ((DisplayInterface)(*self))->Delete(self); }

static int Id(Component self) { return ((DisplayInterface)self)->Id(self); }

static const char* Tag(Component self) { return ((DisplayInterface)self)->Tag(self); }

static void Reset(Component self) { ((DisplayInterface)self)->Reset(self); }

static const DisplayInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .Reset = Reset,
};

const DisplayInterface display = &kTheInterface;
