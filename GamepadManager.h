#include <Arduino.h>
#include <Joystick.h>

class GamepadManager {
  private:
    Joystick_ _joystick;

  public:
    int8_t throttleAxis;
    bool leverButton;
    bool doorsL;
    bool doorsR;

    GamepadManager();

    void begin();
    void send();
}
