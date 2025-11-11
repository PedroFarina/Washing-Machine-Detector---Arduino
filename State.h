#ifndef STATE
#define STATE

class State {
  public:
    bool vibrationDetected();
    virtual State* loop();
    bool motionDetected = false;
};

#endif