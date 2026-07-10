#pragma once

#include <Arduino.h>
#include <Joystick.h>
#include "LeverConfig.h"

class GamepadManager {
  private:
    Joystick_ _joystick;
    int8_t _throttleAxis;

  public:
    bool leverButton;
    bool doorsL;
    bool doorsR;

    GamepadManager();

    void setThrottleAxis(int8_t value);

    void begin();
    void send();
};
