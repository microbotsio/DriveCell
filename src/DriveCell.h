#ifndef DRIVECELL_H
#define DRIVECELL_H

#include <Arduino.h>

#if defined(ARDUINO_ARCH_ESP32)

#define DRIVE_TIMER 8
#define DRIVE_BASE_FREQ 20000
#define DC_MAX_NUM 10

class DriveCell {
private:
  byte _IN1;
  byte _IN2;
  bool _state = 1;
  uint8_t _tnum = 0;

public:
  DriveCell(byte IN1, byte IN2);
  void Init();
  void Run(bool smooth, uint8_t power_percent, uint16_t flip_speed_ms);
  void Buzz(uint16_t us_buzz);
  void Drive(bool direction, uint8_t power_percent);
  void Pulse(bool direction, uint8_t ms_duration);
  void Tone();
  void Toggle(uint8_t power_percent);
};
#else
class DriveCell {
private:
  byte _IN1;
  byte _IN2;
  bool _state = 1;
  uint8_t _tnum = 0;

public:
  DriveCell(byte IN1, byte IN2);
  void Init();
  void Run( uint16_t flip_speed_ms);
  void Buzz(uint16_t us_buzz);
  void Pulse(bool direction, uint8_t ms_duration);
  void Tone();
  void Toggle();
};
#endif
#endif