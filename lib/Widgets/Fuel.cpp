#include "Fuel.h"

void Fuel::begin(MCUFRIEND_kbv tft, uint16_t maxFuel)
{
    fuelBar.begin(tft, 0, maxFuel, 20, SCREEN_H - 50, SCREEN_W - 30, 50, BACKGROUND, ORANGE, FUEL);
    fuelBar.update(maxFuel);
}

void Fuel::update(uint16_t fuel)
{
    if (fuel != curFuel) {
        curFuel = fuel;
        fuelBar.update(fuel);
    }
}
