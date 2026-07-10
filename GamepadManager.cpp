#include "GamepadManager.h"

GamepadManager::GamepadManager() : _joystick(
    JOYSTICK_DEFAULT_REPORT_ID, 
    JOYSTICK_TYPE_GAMEPAD,
    3, 0,                 // Buttons, hat switches
    true, true, false,    // X, Y, Z axes
    false, false, false,  // Rx, Ry, Rz rotations
    false, false,         // Rudder, throttle
    false, false, false   // Accelerator, brake, steering
) {}

void GamepadManager::setThrottleAxis(int8_t value) {
  if (value > LeverConfig::AXIS_MAX) _throttleAxis = LeverConfig::AXIS_MAX;
  else if (value < LeverConfig::AXIS_MIN) _throttleAxis = LeverConfig::AXIS_MIN;
  else _throttleAxis = value;
}

void GamepadManager::begin() {
  _joystick.begin();
  _joystick.setXAxisRange(LeverConfig::AXIS_MIN, LeverConfig::AXIS_MAX);
}

void GamepadManager::send() {
  _joystick.setXAxis(_throttleAxis);
  _joystick.setButton(0, leverButton);
  _joystick.setButton(1, doorsL);
  _joystick.setButton(2, doorsR);

  _joystick.sendState();
}
