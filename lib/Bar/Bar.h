#ifndef BAR_H
#define BAR_H

#include <stdint.h>
#include <MCUFRIEND_kbv.h>
#include <Icon.h>
#include <Game.h>

class Bar {
    private:
        MCUFRIEND_kbv tft;
        uint16_t width;
        uint16_t height;
        uint16_t positionX;
        uint16_t positionY;
        uint16_t backgroundColor;
        uint16_t foregroundColor;
        IconType iconType = EMPTY;
        void draw(uint8_t newValue, uint16_t color);
    
    public:
        void begin(MCUFRIEND_kbv tft, uint16_t width, uint16_t height, 
                uint16_t positionX, uint16_t positionY, uint16_t backgroundColor, uint16_t foregroundColor, IconType iconType);
        void update(uint8_t value);
        void Bar::update(uint8_t value, uint16_t color);
};

#endif
