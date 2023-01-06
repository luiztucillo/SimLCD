#ifndef BAR_H
#define BAR_H

#include <stdint.h>
#include <MCUFRIEND_kbv.h>
#include <Icon.h>

class Bar {
    private:
        MCUFRIEND_kbv tft;
        uint16_t minValue;
        uint16_t maxValue;
        uint16_t width;
        uint16_t height;
        uint16_t positionX;
        uint16_t positionY;
        uint16_t backgroundColor;
        uint16_t foregroundColor;
        Icon icon = Icon();
        uint16_t iconX;
        uint16_t iconY;
        uint16_t iconColor;
    
    public:
        void begin(MCUFRIEND_kbv tft, uint16_t minValue, uint16_t maxValue, uint16_t width, uint16_t height, uint16_t positionX, uint16_t positionY, uint16_t backgroundColor, uint16_t foregroundColor);
        void setIcon(Icon icon, uint16_t iconX, uint16_t iconY, uint16_t iconColor);
        void update(uint16_t value);
};

#endif
