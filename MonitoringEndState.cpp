#include "IdleState.h"
#include "MonitoringEndState.h"
#include <Arduino.h>

const int fourMinutes = 240000;

MonitoringEndState::MonitoringEndState() {
  lastVibration = millis();
  Serial.println("Monitoring End State");
}

State* MonitoringEndState::loop() {
  if(vibrationDetected()) {
    lastVibration = millis();
  }
  if(millis() - lastVibration >= fourMinutes) {
    motionDetected = true;
    return new IdleState();
  }
  return nullptr;
}