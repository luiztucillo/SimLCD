
#ifndef GEAR_H
#define GEAR_H

#include <stdint.h>
#include <MCUFRIEND_kbv.h>
#include <Game.h>

class Gear {
private:
    MCUFRIEND_kbv tft;
    uint16_t curGear = 1;
    char gears[11] = {'R', 'N', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    void draw();
public:
    void begin(MCUFRIEND_kbv tft);
    void update(uint16_t gear);
};

#endif
