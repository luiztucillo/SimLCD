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
    float fraction = ((float) (100 * (curValue / 1000) / (maxValue - minValue))) / 100;

    hsv c1 = Color::intToHsv(minColor);
    hsv c2 = Color::intToHsv(maxColor);

    hsv finalColor = {};
    finalColor.h = c1.h * (1 - fraction) + c2.h * fraction;
    finalColor.s = c1.s * (1 - fraction) + c2.s * fraction;
    finalColor.v = c1.v * (1 - fraction) + c2.v * fraction;

    hsv shadow = {};
    shadow.h = finalColor.h;
    shadow.s = finalColor.s;
    shadow.v = finalColor.v - 0.3 < 0 ? 0 : finalColor.v - 0.3;

    hsv specular = {};
    specular.h = finalColor.h;
    specular.s = finalColor.s - 0.3 < 0 ? 0 : finalColor.s - 0.3;
    specular.v = finalColor.v;

    led.drawLed(x, y, Color::hsvToInt(shadow), Color::hsvToInt(finalColor), Color::hsvToInt(specular), Color::hsvToInt(shadow));
}
