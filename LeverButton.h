#pragma once

#include <Arduino.h>
#include "PinConfig.h"
#include "GamepadManager.h"

class LeverButton {
  private:
    GamepadManager* _gamepadManager;

  public:
    LeverButton(GamepadManager* gamepadManagerRef);

    void begin();
    void update();
};
