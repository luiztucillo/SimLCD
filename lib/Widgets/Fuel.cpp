#include "Fuel.h"

void Fuel::begin(MCUFRIEND_kbv tft)
{
    fuelBar.begin(tft, 20, SCREEN_H - 50, SCREEN_W - 30, 50, BACKGROUND, ORANGE, FUEL);
    fuelBar.update(100);
}

void Fuel::update(uint8_t fuelPercentage)
{
    if (fuelPercentage != curFuelPercentage) {
        curFuelPercentage = fuelPercentage;
        fuelBar.update(fuelPercentage);
    }
}
