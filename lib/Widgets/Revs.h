
#ifndef REVS_H
#define REVS_H

#include <stdint.h>
#include <MCUFRIEND_kbv.h>
#include <LedAutoColored.h>
#include <Game.h>

class Revs {
private:
    MCUFRIEND_kbv tft;
    uint8_t curRpmPercentage = 0;
    void draw();
public:
    void begin(MCUFRIEND_kbv tft);
    void update(uint8_t rpmPercentage);
};

#endif
