#include "PinConfig.h"
#include "LeverButton.h"

LeverButton::LeverButton(GamepadManager* gamepadManagerRef) {
  _gamepadManager = gamepadManagerRef;
}

void LeverButton::begin() {

}

void LeverButton::update() {
  _gamepadManager->leverButton = (digitalRead(PinConfig::LEVER_BUTTON) == LOW);
}
