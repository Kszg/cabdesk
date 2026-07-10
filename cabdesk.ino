#include "LeverButton.h"
#include "LeverAxis.h"
#include "GamepadManager.h"
#include "DoorButtons.h"
#include "PinConfig.h"

GamepadManager _gamepadManager;

LeverAxis _leverAxis(&_gamepadManager);
LeverButton _leverButton(&_gamepadManager);
DoorButtons _doorButtons(&_gamepadManager);

void setup() {
  PinConfig::initPins();

  _leverAxis.begin();
  _leverButton.begin();
  _doorButtons.begin();

  _gamepadManager.begin();
}

void loop() {
  _leverAxis.update();
  _leverButton.update();
  _doorButtons.update();

  _gamepadManager.send();

  delay(20);
}
