#ifndef ICON_H
#define ICON_H

#include <stdint.h>
#include <MCUFRIEND_kbv.h>

enum IconType
{
    ERS,
    FUEL,
    EMPTY
};

class Icon {
public:
    void drawErsIcon(MCUFRIEND_kbv tft, uint16_t offsetX, uint16_t offsetY);
    void drawFuelIcon(MCUFRIEND_kbv tft, uint16_t offsetX, uint16_t offsetY);
    void drawIcon(IconType type, MCUFRIEND_kbv tft, uint16_t offsetX, uint16_t offsetY);
};

#endif
