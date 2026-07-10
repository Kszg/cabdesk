#include "DevMode.h"

DevMode::DevMode(GamepadManager* gamepadManagerRef) {
  _gamepadManager = gamepadManagerRef;
}

void DevMode::printInfo() {
  Serial.print("Pot: ");
  Serial.print(analogRead(PinConfig::LEVER_POT));
  Serial.print(" | ");
  Serial.print("Axis: ");
  Serial.println(_axisValue);
}

void DevMode::begin() {

}

bool _doorLPressedLastFrame = false;
bool _doorRPressedLastFrame = false;

void DevMode::update() {
  bool doorLPressed = (digitalRead(PinConfig::DOOR_L) == LOW);
  bool doorClosePressed = (digitalRead(PinConfig::DOOR_CLOSE) == LOW);
  bool doorRPressed = (digitalRead(PinConfig::DOOR_R) == LOW);

  uint8_t changeAmount = doorClosePressed ? 10 : 1;

  if (doorLPressed && !_doorLPressedLastFrame) _axisValue -= changeAmount;
  if (doorRPressed && !_doorRPressedLastFrame) _axisValue += changeAmount;

  if (_axisValue > LeverConfig::AXIS_MAX) _axisValue = LeverConfig::AXIS_MAX;
  if (_axisValue < LeverConfig::AXIS_MIN) _axisValue = LeverConfig::AXIS_MIN;

  printInfo();

  _gamepadManager->setThrottleAxis(_axisValue);

  _doorLPressedLastFrame = doorLPressed;
  _doorRPressedLastFrame = doorRPressed;
}
