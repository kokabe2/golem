// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef SRC_UTIL_ONE_SHOT_TIMER_MANAGER_H_
#define SRC_UTIL_ONE_SHOT_TIMER_MANAGER_H_

typedef void (*OneShotTimerHandlerDelegate)(void);
typedef struct {
  void (*Create)(void);
  void (*Destroy)(void);
  void (*Add)(OneShotTimerHandlerDelegate handler, int milliseconds);
  void (*Clean)(void);
  int (*GetMaxInspectionsOnceEveryClean)(void);
  void (*SetMaxInspectionsOnceEveryClean)(int max);
} OneShotTimerManagerMethodStruct;
typedef const OneShotTimerManagerMethodStruct* OneShotTimerManagerMethod;

extern const OneShotTimerManagerMethod oneShotTimerManager;

#endif  // SRC_UTIL_ONE_SHOT_TIMER_MANAGER_H_
