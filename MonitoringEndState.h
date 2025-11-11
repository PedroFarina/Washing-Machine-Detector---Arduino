#ifndef MONITORING_END_STATE
#define MONITORING_END_STATE

#include "State.h"

struct MonitoringEndState: State {
  MonitoringEndState();
  unsigned long lastVibration;
  State* loop();
};

#endif