// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_GOLEM_H_
#define V1_GOLEM_H_

typedef void (*GolemBackgroundProcess)(void);
typedef struct {
  void (*Create)(void);
  void (*Destroy)(void);
  void (*SetWakeUpInterval)(int milliseconds);
  void (*AddBackgroundProcess)(GolemBackgroundProcess process, int interval_in_milliseconds);
} GolemMethodStruct;
typedef const GolemMethodStruct* GolemMethod;

extern const GolemMethod golem;

#endif  // V1_GOLEM_H_
