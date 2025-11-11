#include "IdleState.h"
#include "MonitoringEndState.h"
#include <Arduino.h>

const int fiveMinutes = 300000;

MonitoringEndState::MonitoringEndState() {
  lastVibration = millis();
  Serial.println("Monitoring End State");
}

State* MonitoringEndState::loop() { 
  if(millis() - lastVibration >= fiveMinutes) {
    motionDetected = true;
    return new IdleState();
  }
  return nullptr;
}