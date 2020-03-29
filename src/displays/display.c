// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "display.h"

#include "display_private.h"

static void Delete(Display* self) { (*self)->impl->Delete(self); }

static int Id(Display self) { return self->impl->Id(self); }

static const char* Tag(Display self) { return self->impl->Tag(self); }

static void Reset(Display self) { self->impl->Reset(self); }

static const DisplayInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .Reset = Reset,
};

const DisplayInterface display = &kTheInterface;
