// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "component_factory.h"

#include "component_factory_private.h"

static void Delete(ComponentFactory* self) { (*self)->impl->Delete(self); }

static ComponentInterface Make(ComponentFactory self, int id) { return self->impl->Make(self, id); }

static const ComponentFactoryInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Make = Make,
};

const ComponentFactoryInterface componentFactory = &kTheInterface;
