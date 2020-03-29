// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "sensor_factory.h"

#include "sensor_factory_private.h"

static void Delete(SensorFactory* self) { (*self)->impl->Delete(self); }

static SensorInterface Make(SensorFactory self, int id) { return self->impl->Make(self, id); }

static const SensorFactoryInterfaceStruct kTheInterface = {
    .Delete = Delete, .Make = Make,
};

const SensorFactoryInterface sensorFactory = &kTheInterface;
