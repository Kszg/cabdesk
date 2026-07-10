#include "LeverAxis.h"

LeverAxis::LeverAxis(GamepadManager* gamepadManagerRef) {
  _gamepadManager = gamepadManagerRef;
}

void LeverAxis::begin() {

}

void LeverAxis::update() {
  uint16_t potValue = analogRead(PinConfig::LEVER_POT);
  int8_t axisValue = 0;
  
  bool traction = (potValue >= LeverConfig::POT_TRACTION_MIN);
  bool leverButtonPressed = (digitalRead(PinConfig::LEVER_BUTTON) == LOW);

  if (traction && !_tractionLastFrame && !leverButtonPressed) { // Lever moved to throttle position in this frame, but the cap wasn't pressed
    traction = false;
  }
  else if (potValue >= LeverConfig::POT_TRACTION_MIN) { // Traction
    axisValue = map(potValue, LeverConfig::POT_TRACTION_MIN, LeverConfig::POT_TRACTION_MAX, LeverConfig::AXIS_TRACTION_MIN, LeverConfig::AXIS_TRACTION_MAX);
  }
  else { // Braking
    if (potValue <= LeverConfig::POT_EBRAKE_MIN) axisValue = LeverConfig::AXIS_EBRAKE_VALUE;
    else {
      axisValue = map(potValue, LeverConfig::POT_BRAKING_MIN, LeverConfig::POT_BRAKING_MAX, LeverConfig::AXIS_BRAKING_MIN, LeverConfig::AXIS_BRAKING_MAX);
    }
  }

  _gamepadManager->setThrottleAxis(axisValue);

  _tractionLastFrame = traction;
}
