#ifndef LED_AUTO_COLORED_H
#define LED_AUTO_COLORED_H

#include <MCUFRIEND_kbv.h>
#include <Led.h>

class LedAutoColored {
private:
    Led led;
    uint16_t minValue;
    uint16_t maxValue;
    uint16_t minColor;
    uint16_t maxColor;

public:
    int getWidth();
    void begin(MCUFRIEND_kbv tft, uint16_t minValue, uint16_t maxValue, uint16_t minColor, uint16_t maxColor);
    void drawLed(int x, int y, uint16_t curValue);
};

#endif
