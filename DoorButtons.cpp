#include "DoorButtons.h"

DoorButtons::DoorButtons(GamepadManager* gamepadManagerRef) {
  _gamepadManager = gamepadManagerRef;
}

void DoorButtons::begin() {

}

bool _closePressedLastFrame = false;

void DoorButtons::update() {
  bool leftPressed = (digitalRead(PinConfig::DOOR_L) == LOW);
  bool closePressed = (digitalRead(PinConfig::DOOR_CLOSE) == LOW);
  bool rightPressed = (digitalRead(PinConfig::DOOR_R) == LOW);

  if (closePressed && (_leftOpen || _rightOpen || _closePressedLastFrame)) {
    _gamepadManager->doorsL = _leftOpen;
    _gamepadManager->doorsR = _rightOpen;
  }
  else {
    _gamepadManager->doorsL = false;
    _gamepadManager->doorsR = false;

    if (leftPressed) {
      _gamepadManager->doorsL = true;
      _leftOpen = true;
    }

    if (rightPressed) {
      _gamepadManager->doorsR = true;
      _rightOpen = true;
    }
  }

  if (_closePressedLastFrame && !closePressed) {
    _leftOpen = false;
    _rightOpen = false;
  }

  _closePressedLastFrame = closePressed;
}
