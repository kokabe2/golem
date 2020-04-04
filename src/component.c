// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "component.h"

static void Delete(Component* self) { (*self)->Delete(self); }

static int Id(Component self) { return self->Id(self); }

static const char* Tag(Component self) { return self->Tag(self); }

static const ComponentInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
};

const ComponentInterface component = &kTheInterface;
