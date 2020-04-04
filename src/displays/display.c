// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "display.h"

#include "component_private.h"

static void Delete(Component* self) { ((DisplayInterface)((*self)->impl))->Delete(self); }

static int Id(Component self) { return ((DisplayInterface)(self->impl))->Id(self); }

static const char* Tag(Component self) { return ((DisplayInterface)(self->impl))->Tag(self); }

static void Reset(Component self) { ((DisplayInterface)(self->impl))->Reset(self); }

static const DisplayInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .Reset = Reset,
};

const DisplayInterface display = &kTheInterface;
