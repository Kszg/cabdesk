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

void GamepadManager::begin() {
  _joystick.begin();
  _joystick.setXAxisRange(-100, 100);
}

void GamepadManager::send() {
  _joystick.setXAxis(throttleAxis);
  _joystick.setButton(0, leverButton);
  _joystick.setButton(1, doorsL);
  _joystick.setButton(2, doorsR);

  _joystick.sendState();
}
