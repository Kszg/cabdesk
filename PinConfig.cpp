#include "Arduino.h"
#include "PinConfig.h"

namespace PinConfig {
  void initPins() {
    pinMode(LEVER_BUTTON, INPUT_PULLUP);
    pinMode(DOOR_L, INPUT_PULLUP);
    pinMode(DOOR_CLOSE, INPUT_PULLUP);
    pinMode(DOOR_R, INPUT_PULLUP);
  }
}
