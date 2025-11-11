#ifndef IDLE_STATE
#define IDLE_STATE

#include "State.h"

struct IdleState: State {
  IdleState();
  State* loop();
};

#endif