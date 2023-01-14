
#ifndef LAPTIME_H
#define LAPTIME_H

#include <stdint.h>
#include <MCUFRIEND_kbv.h>
#include <Game.h>

class LapTime {
private:
    MCUFRIEND_kbv tft;
    uint32_t curTime = 0;
    uint16_t size = 4;
    uint16_t x = 0;
    uint16_t y = 0;
    uint16_t color = WHITE;
    void draw();
    void format(char* buffer);
public:
    void begin(MCUFRIEND_kbv tft, uint16_t size, uint16_t x, uint16_t y, uint16_t color);
    void update(uint32_t time);
};

#endif
