
#ifndef CURLAP_H
#define CURLAP_H

#include <stdint.h>
#include <MCUFRIEND_kbv.h>
#include <Game.h>

class CurLap {
private:
    MCUFRIEND_kbv tft;
    uint16_t curLap = 0;
    void draw();
public:
    void begin(MCUFRIEND_kbv tft);
    void update(uint16_t lap);
};

#endif
