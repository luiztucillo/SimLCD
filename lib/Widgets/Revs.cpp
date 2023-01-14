#include "Revs.h"

void Revs::draw()
{
    tft.setTextSize(3);
    tft.fillRect(10, 50, 100, 22, BACKGROUND);
    tft.setCursor(10, 50);
    tft.setTextColor(WHITE);
    tft.print(curRpm);

    int offsetX = 22;
    int offsetY = 22; 
    for (int i = 0; i < 8; i ++) {
        revLeds.drawLed(offsetX, offsetY, curRpm);
        offsetX += revLeds.getWidth() + 13;
    }
}

void Revs::begin(MCUFRIEND_kbv tft, uint16_t maxRpm) {
    revLeds.begin(tft, 0, maxRpm, 0x07E0, RED);
    this->tft = tft;
    draw();
}

void Revs::update(uint16_t rpm)
{
    if (rpm != curRpm) {
        curRpm = rpm;
        draw();
    }
}
