// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef SRC_UTIL_SCHEDULED_PROCESS_MANAGER_H_
#define SRC_UTIL_SCHEDULED_PROCESS_MANAGER_H_

typedef void (*ScheduledProcessDelegate)(void);
typedef struct {
  void (*Create)(void);
  void (*Destroy)(void);
  void (*Add)(ScheduledProcessDelegate process, int milliseconds);
  void (*Kick)(void);
} ScheduledProcessManagerMethodStruct;
typedef const ScheduledProcessManagerMethodStruct* ScheduledProcessManagerMethod;

extern const ScheduledProcessManagerMethod scheduledProcessManager;

#endif  // SRC_UTIL_SCHEDULED_PROCESS_MANAGER_H_
