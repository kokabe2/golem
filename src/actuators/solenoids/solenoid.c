// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "solenoid.h"

static void Delete(Component* self) { ((SolenoidInterface)(*self))->Delete(self); }

static int Id(Component self) { return ((SolenoidInterface)self)->Id(self); }

static const char* Tag(Component self) { return ((SolenoidInterface)self)->Tag(self); }

static const char* State(Component self) { return ((SolenoidInterface)self)->State(self); }

static bool IsUnlocked(Component self) { return ((SolenoidInterface)self)->IsUnlocked(self); }

static void Lock(Component self) { ((SolenoidInterface)self)->Lock(self); }

static void Unlock(Component self) { ((SolenoidInterface)self)->Unlock(self); }

static void ForceUnlock(Component self) { ((SolenoidInterface)self)->ForceUnlock(self); }

static const SolenoidInterfaceStruct kTheInterface = {
    .Delete = Delete,
    .Id = Id,
    .Tag = Tag,
    .State = State,
    .IsUnlocked = IsUnlocked,
    .Lock = Lock,
    .Unlock = Unlock,
    .ForceUnlock = ForceUnlock,
};

const SolenoidInterface solenoid = &kTheInterface;
