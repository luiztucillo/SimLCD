#ifndef SPEED_H
#define SPEED_H

#include <stdint.h>
#include <MCUFRIEND_kbv.h>
#include <Game.h>

class Speed {
private:
    MCUFRIEND_kbv tft;
    uint16_t curSpeed = 0;
    void draw();
public:
    void begin(MCUFRIEND_kbv tft);
    void update(uint16_t speed);
};

#endif
