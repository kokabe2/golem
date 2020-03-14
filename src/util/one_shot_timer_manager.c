// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#include "one_shot_timer_manager.h"

#include "bleu/v1/list.h"
#include "malkt/v1/one_shot_timer.h"

static List the_timers;
static int inspections_max;

static void DeleteOneShotTimer(void** x) { timer->Delete((Timer*)x); }

static DeleterInterfaceStruct OneShotTimerDeleter = {
    .Delete = DeleteOneShotTimer,
};

static void Create(void) {
  the_timers = list->New();
  list->SetItemDeleter(the_timers, &OneShotTimerDeleter);
  inspections_max = 16;
}

static void Destroy(void) { list->Delete(&the_timers); }

static void Add(OneShotTimerHandlerDelegate handler, int milliseconds) {
  Timer t = oneShotTimer->New(handler, milliseconds);
  list->Add(the_timers, t);
}

inline static int AdjustInspections(void) {
  return inspections_max > list->Count(the_timers) ? list->Count(the_timers) : inspections_max;
}

inline static Timer PopFromListHead(void) { return list->Pop(the_timers, 0); }

inline static void DeleteOrReturnToList(Timer t) {
  if (oneShotTimer->IsDone(t))
    timer->Delete(&t);
  else
    list->Add(the_timers, t);
}

static void Clean(void) {
  int inspections = AdjustInspections();
  for (int i = 0; i < inspections; ++i) {
    Timer t = PopFromListHead();
    DeleteOrReturnToList(t);
  }
}

static int GetMaxInspectionsOnceEveryClean(void) { return inspections_max; }

static void SetMaxInspectionsOnceEveryClean(int max) { inspections_max = max; }

static const OneShotTimerManagerMethodStruct kTheMethod = {
    .Create = Create,
    .Destroy = Destroy,
    .Add = Add,
    .Clean = Clean,
    .GetMaxInspectionsOnceEveryClean = GetMaxInspectionsOnceEveryClean,
    .SetMaxInspectionsOnceEveryClean = SetMaxInspectionsOnceEveryClean,
};

const OneShotTimerManagerMethod oneShotTimerManager = &kTheMethod;
