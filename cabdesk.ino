// #define DEV_MODE

#include "PinConfig.h"
#include "GamepadManager.h"

#ifdef DEV_MODE
#include "DevMode.h"
#else
#include "LeverButton.h"
#include "LeverAxis.h"
#include "DoorButtons.h"
#endif

GamepadManager _gamepadManager;

#ifdef DEV_MODE
DevMode _devMode(&_gamepadManager);
#else
LeverAxis _leverAxis(&_gamepadManager);
LeverButton _leverButton(&_gamepadManager);
DoorButtons _doorButtons(&_gamepadManager);
#endif

void setup() {
  PinConfig::initPins();

  #ifdef DEV_MODE
  _devMode.begin();
  #else
  _leverAxis.begin();
  _leverButton.begin();
  _doorButtons.begin();
  #endif

  _gamepadManager.begin();

  Serial.begin(9600);

  while (!Serial) {
    ;
  }

  Serial.println("CabDesk");
}

void loop() {
  #ifdef DEV_MODE
  _devMode.update();
  #else
  _leverAxis.update();
  _leverButton.update();
  _doorButtons.update();
  #endif

  _gamepadManager.send();

  delay(20);
}