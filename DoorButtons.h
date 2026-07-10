#pragma once

#include <Arduino.h>
#include "PinConfig.h"
#include "GamepadManager.h"

class DoorButtons {
  private:
    GamepadManager* _gamepadManager;

    bool _leftOpen;
    bool _rightOpen;

  public:
    DoorButtons(GamepadManager* gamepadManagerRef);

    void begin();
    void update();
};
