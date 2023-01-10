#ifndef ICON_H
#define ICON_H

#include <stdint.h>
#include <MCUFRIEND_kbv.h>

enum IconType
{
    ERS,
    FUEL
};

class Icon {
private:
    IconType icon;
    void drawErsIcon(MCUFRIEND_kbv tft, uint16_t offsetX, uint16_t offsetY);
    void drawFuelIcon(MCUFRIEND_kbv tft, uint16_t offsetX, uint16_t offsetY);

public:
    Icon(IconType icon);
    void drawIcon(MCUFRIEND_kbv tft, uint16_t offsetX, uint16_t offsetY);
};

#endif
