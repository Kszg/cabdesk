#pragma once

#include <Arduino.h>

namespace PinConfig {
  constexpr uint8_t LEVER_POT = 0;
  constexpr uint8_t LEVER_BUTTON = 13;
  constexpr uint8_t DOOR_L = 12;
  constexpr uint8_t DOOR_CLOSE = 11;
  constexpr uint8_t DOOR_R = 10;

  void initPins();
}
