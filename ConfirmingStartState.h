#ifndef CONFIRMING_START_STATE
#define CONFIRMING_START_STATE

#include "State.h"

struct ConfirmingStartState: State {
  ConfirmingStartState();
  unsigned long start;
  unsigned long lastVibration;
  State* loop();
};

#endif