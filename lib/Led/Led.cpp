#include "Led.h"

void Led::begin(MCUFRIEND_kbv tft)
{
  this->tft = tft;
}

int Led::getWidth()
{
  return Led::WIDTH * 2;
}

void Led::drawLed(int x, int y, uint16_t shadow, uint16_t bright, uint16_t specular, uint16_t miniShadow)
{
    tft.fillCircle(x, y, Led::WIDTH, specular);
    tft.fillCircle(x, y, Led::WIDTH - 1, 0x7BEF);
    tft.fillCircle(x, y, Led::WIDTH - 2, 0x52AA);
    tft.fillCircle(x, y, Led::WIDTH - 3, shadow);            // shadow
    tft.fillCircle(x, y, Led::WIDTH - 5, bright);             // bright
    tft.fillCircle(x - 4, y - 4, Led::WIDTH - 8, specular);   // specular
    tft.fillCircle(x + 5, y + 5, Led::WIDTH - 9, miniShadow); // mini-shadow
    tft.fillCircle(x, y, Led::WIDTH - 7, bright);             // bright
}

void Led::drawRedLed(int x, int y) {
  drawLed(x, y, 0xA082, 0xF800, 0xFACB, 0x9041);
}

void Led::drawBlueLed(int x, int y) {
  drawLed(x, y, 0x0215, 0x1B7E,  0x447F, 0x014D);
}

void Led::drawYellowLed(int x, int y) {
  drawLed(x, y, 0xBC40, 0xD4C0,  0xFE25, 0x8B20);
}

void Led::drawOffLed(int x, int y) {
  drawLed(x, y, 0x4228, 0x630C,  0x8C51, 0x4A69);
}
