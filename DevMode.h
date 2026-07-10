#pragma once

#include <Arduino.h>
#include "PinConfig.h"
#include "LeverConfig.h"
#include "GamepadManager.h"

class DevMode {
  private:
    GamepadManager* _gamepadManager;

    int8_t _axisValue;

    void printInfo();

  public:
    DevMode(GamepadManager* gamepadManagerRef);

    void begin();
    void update();
};
