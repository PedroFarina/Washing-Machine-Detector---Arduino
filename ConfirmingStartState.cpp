#include "IdleState.h"
#include "ConfirmingStartState.h"
#include "MonitoringEndState.h"
#include <Arduino.h>

const int thirtySeconds = 30000;
const int fiveMinutes = 300000;

ConfirmingStartState::ConfirmingStartState() {
  start = millis();
  lastVibration = start;
  Serial.println("Confirming Start State");
}

State* ConfirmingStartState::loop() { 
  if(vibrationDetected()) {
    lastVibration = millis();
  }
  if(millis() - lastVibration >= thirtySeconds) {
    return new IdleState();
  }
  if(millis() - start >= fiveMinutes) {
    return new MonitoringEndState();
  }
  return nullptr;
}