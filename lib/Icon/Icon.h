#ifndef ICON_H
#define ICON_H

#include <stdint.h>
#include <MCUFRIEND_kbv.h>

class Icon {
public:
    void drawIcon(MCUFRIEND_kbv tft, uint16_t x, uint16_t y, uint16_t color) {
        return;
    }
};

class IconErs : public Icon {
public:
    void drawIcon(MCUFRIEND_kbv tft, uint16_t x, uint16_t y, uint16_t color);
};

class IconFuel : public Icon {
public:
    void drawIcon(MCUFRIEND_kbv tft, uint16_t x, uint16_t y, uint16_t color);
};

#endif
