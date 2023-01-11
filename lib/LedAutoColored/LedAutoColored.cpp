#include "LedAutoColored.h"
#include <Color.h>

int LedAutoColored::getWidth()
{
    return this->led.getWidth();
}

void LedAutoColored::begin(MCUFRIEND_kbv tft, uint16_t minValue, uint16_t maxValue, uint16_t minColor, uint16_t maxColor)
{
    this->led = Led();
    led.begin(tft);

    this->minValue = minValue / 1000;
    this->maxValue = maxValue / 1000;

    this->minColor = minColor;
    this->maxColor = maxColor;
}

void LedAutoColored::drawLed(int x, int y, uint16_t curValue)
{
    float perc = (float) (100 * (curValue / 1000) / (maxValue - minValue));

    uint16_t offColor = 0x7BEF; 
    uint16_t color;
    if (perc < 70) {
        color = offColor;
    } else if(perc <80) {
        color = 0x1FE0;
    } else if(perc < 95) {
        color = 0xFEE0;
    } else {
        color = 0xF800;
    }

    led.drawSimpleLed(x, y, color);
}
