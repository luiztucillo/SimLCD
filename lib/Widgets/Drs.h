#ifndef DRS_H
#define DRS_H

#include <stdint.h>
#include <MCUFRIEND_kbv.h>
#include <Bar.h>
#include <Game.h>

class Drs {
private:       
    MCUFRIEND_kbv tft;
    bool enabled = false;
    bool available = false;
    bool exists = false;
    void draw();
public:
    void begin(MCUFRIEND_kbv tft);
    void update(bool exists, bool available, bool enabled);
    void clear();
};

#endif
