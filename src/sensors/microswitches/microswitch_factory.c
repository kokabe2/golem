// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "microswitch_factory.h"

#include "microswitch_factory_private.h"

static void Delete(MicroswitchFactory* self) { (*self)->impl->Delete(self); }

static MicroswitchInterface Make(MicroswitchFactory self, int id) { return self->impl->Make(self, id); }

static const MicroswitchFactoryInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Make = Make,
};

const MicroswitchFactoryInterface microswitchFactory = &kTheInterface;
