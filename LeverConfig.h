#pragma once

namespace LeverConfig {
  constexpr uint16_t POT_TRACTION_MIN = 545;
  constexpr uint16_t POT_TRACTION_MAX = 750;
  constexpr uint16_t POT_BRAKING_MAX = 512;
  constexpr uint16_t POT_BRAKING_MIN = 335;
  constexpr uint16_t POT_EBRAKE_MIN = 320;

  constexpr int8_t AXIS_TRACTION_MIN = 15;
  constexpr int8_t AXIS_TRACTION_MAX = 100;
  constexpr int8_t AXIS_NEUTRAL_VALUE = 0;
  constexpr int8_t AXIS_BRAKING_MAX = -5;
  constexpr int8_t AXIS_BRAKING_MIN = -79;
  constexpr int8_t AXIS_EBRAKE_VALUE = -100;

  constexpr int8_t AXIS_MIN = -100;
  constexpr int8_t AXIS_MAX = 100;
}
