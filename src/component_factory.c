// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "component_factory.h"

static void Delete(ComponentFactory* self) { (*self)->Delete(self); }

static Component Make(ComponentFactory self, int id) { return self->Make(self, id); }

static const ComponentFactoryInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Make = Make,
};

const ComponentFactoryInterface componentFactory = &kTheInterface;
