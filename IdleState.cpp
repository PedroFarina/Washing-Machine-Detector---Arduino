#include "IdleState.h"
#include "ConfirmingStartState.h"
#include <Arduino.h>

IdleState::IdleState() {
  Serial.println("Idle State");
}

State* IdleState::loop() {
  if(vibrationDetected()) {
    return new ConfirmingStartState();
  }
  return nullptr;
}