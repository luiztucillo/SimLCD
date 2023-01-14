#ifndef FUEL_H
#define FUEL_H

#include <stdint.h>
#include <MCUFRIEND_kbv.h>
#include <Bar.h>
#include <Game.h>

class Fuel {
private:
    Bar fuelBar = Bar();        
    MCUFRIEND_kbv tft;
    uint16_t curFuel = 0;
public:
    void begin(MCUFRIEND_kbv tft, uint16_t maxFuel);
    void update(uint16_t fuel);
};

#endif
