#pragma once

#include <Arduino.h>
#include "PinConfig.h"
#include "LeverConfig.h"
#include "GamepadManager.h"

class LeverAxis {
  private:
    bool _tractionLastFrame;
    GamepadManager* _gamepadManager;
  
  public:
    LeverAxis(GamepadManager* gamepadManagerRef);

    void begin();
    void update();
};
