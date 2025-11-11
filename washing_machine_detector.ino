// #include "HomeSpan.h"
#include "State.h"
#include "IdleState.h"
#include "ConfirmingStartState.h"
#include "MonitoringEndState.h"
#include "HomeSpan.h"

struct SteadyVibrationSensor: Service::MotionSensor {
  SpanCharacteristic *motion;
  State *currentState;

  SteadyVibrationSensor() : Service::MotionSensor() {
    motion = new Characteristic::MotionDetected(false);
    currentState = new IdleState();
  }

  void setState(State *s) {
    if(s == nullptr) {
      return;
    }
    if(currentState) {
      bool motionDetected = currentState -> motionDetected;
      Serial.println(motionDetected);
      motion -> setVal(motionDetected);
    }
    delete currentState;
    currentState = s;
  }

  void loop() {
    setState(currentState -> loop());
  }
};

void setup() {
  Serial.begin(115200);
  homeSpan.begin(Category::Sensors, "Steady Vibration Detector");
  homeSpan.setPairingCode("11223344");
  pinMode(25, INPUT);
  new SpanAccessory();
    new Service::AccessoryInformation();
      new Characteristic::Identify();
      new Characteristic::Name("Steady Vibration Detector");
  new SteadyVibrationSensor();
}

void loop() {
  homeSpan.poll();
}