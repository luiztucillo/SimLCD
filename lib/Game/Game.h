#ifndef GAME_H
#define GAME_H

#include <Arduino.h>

#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GRAY    0x7BEF
#define BACKGROUND 0x0101
#define ORANGE 0xDC40

#define SCREEN_W 320
#define SCREEN_H 240

struct DataLoader
{
  uint16_t speed = 0;
  uint16_t rpm = 0;
  uint16_t gear = 0;
  uint16_t maxRpm = 0;
  uint8_t status = 0;
  uint16_t fuel = 0;
  uint16_t maxFuel = 0;
  uint8_t player = 0;
  uint32_t curTime = 0;
  uint32_t lastTime = 0;
  uint32_t bestTime = 0;
  uint8_t ersPowerLevel = 0;
  uint8_t ersChargePercentage = 0;
  uint8_t booleans = 0;
  // bool hasErs = false;
  // bool hasDrs = false;
  // bool kersInput = false;
  // bool drsAvailable = false;
  // bool drsEnabled = false;
  // bool placeHolder1 = false;
  // bool placeHolder2 = false;
  // bool placeHolder3 = false;
};

class Game {
    private:
        void updateBooleans();
    public:
        DataLoader data;
        void begin();
        bool update();
        bool hasErs = false;
        bool hasDrs = false;
        bool kersInput = false;
        bool drsAvailable = false;
        bool drsEnabled = false;
};

#endif
