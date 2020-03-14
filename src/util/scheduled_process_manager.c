// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "scheduled_process_manager.h"

#include "bleu/v1/heap.h"
#include "bleu/v1/list.h"
#include "malkt/v1/uptime.h"

static List the_processes;
static uint64_t last_kick_time;

typedef struct {
  int interval;
  int elapsed;
  ScheduledProcessDelegate process;
} ScheduledProcessStruct, *ScheduledProcess;

static void DeleteProcess(void** x) { heap->Delete(x); }

static DeleterInterfaceStruct ProcessDeleter = {
    .Delete = DeleteProcess,
};

static void Create(void) {
  the_processes = list->New();
  list->SetItemDeleter(the_processes, &ProcessDeleter);
  last_kick_time = 0;
}

static void Destroy(void) { list->Delete(&the_processes); }

inline static ScheduledProcess NewScheduledProcess(ScheduledProcessDelegate process, int milliseconds) {
  ScheduledProcess sp = (ScheduledProcess)heap->New(sizeof(ScheduledProcessStruct));
  sp->process = process;
  sp->interval = milliseconds;
  return sp;
}

static void Add(ScheduledProcessDelegate process, int milliseconds) {
  ScheduledProcess sp = NewScheduledProcess(process, milliseconds);
  list->Add(the_processes, sp);
}

inline static void RunProcessIfNeeded(ScheduledProcess sp) {
  if (sp->elapsed >= sp->interval) {
    sp->elapsed = 0;
    sp->process();
  }
}

static void RunProcesses(uint64_t now) {
  int elapsed = now - last_kick_time;
  for (int i = 0; i < list->Count(the_processes); ++i) {
    ScheduledProcess sp = list->Get(the_processes, i);
    sp->elapsed += elapsed;
    RunProcessIfNeeded(sp);
  }
}

static void Kick(void) {
  uint64_t now = uptime->Get();
  RunProcesses(now);
  last_kick_time = now;
}

static const ScheduledProcessManagerMethodStruct kTheMethod = {
    .Create = Create,
    .Destroy = Destroy,
    .Add = Add,
    .Kick = Kick,
};

const ScheduledProcessManagerMethod scheduledProcessManager = &kTheMethod;
