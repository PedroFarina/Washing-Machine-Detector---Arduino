#include "State.h"
#include <Arduino.h>

bool State::vibrationDetected() { return digitalRead(25); }
State* State::loop() { return nullptr; }