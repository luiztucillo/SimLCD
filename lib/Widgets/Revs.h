
#ifndef REVS_H
#define REVS_H

#include <stdint.h>
#include <MCUFRIEND_kbv.h>
#include <LedAutoColored.h>
#include <Game.h>

class Revs {
private:
    LedAutoColored revLeds = LedAutoColored();
    MCUFRIEND_kbv tft;
    uint16_t curRpm = 0;
    void draw();
public:
    void begin(MCUFRIEND_kbv tft, uint16_t maxRpm);
    void update(uint16_t rpm);
};

#endif
