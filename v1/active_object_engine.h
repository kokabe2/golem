// Copyright(c) 2020 Ken Okabe
// This software is released under the MIT License, see LICENSE.
#ifndef V1_ACTIVE_OBJECT_ENGINE_H_
#define V1_ACTIVE_OBJECT_ENGINE_H_

typedef void (*CommandDelegate)(void* instance);
typedef struct {
  void (*Create)(void);
  void (*Destroy)(void);
  void (*AddCommand)(void* instance, CommandDelegate delegate);
} ActiveObjectEngineMethodStruct;
typedef const ActiveObjectEngineMethodStruct* ActiveObjectEngineMethod;

extern const ActiveObjectEngineMethod activeObjectEngine;

#endif  // V1_ACTIVE_OBJECT_ENGINE_H_
