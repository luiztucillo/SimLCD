#include "Revs.h"

void Revs::draw()
{
    uint16_t maxWidth = SCREEN_W - 2;

    uint16_t filled = maxWidth * curRpmPercentage / 100;
    uint16_t unfilled = maxWidth - filled;

    tft.fillRect(1 + filled, 1, unfilled, 28, BACKGROUND);
    tft.fillRect(1, 1, filled, 28, YELLOW);
}

void Revs::begin(MCUFRIEND_kbv tft) {
    tft.drawRect(0, 0, SCREEN_W, 30, 0xFFFF);
    this->tft = tft;
    draw();
}

void Revs::update(uint8_t rpmPercentage)
{
    if (rpmPercentage != curRpmPercentage) {
        curRpmPercentage = rpmPercentage;
        draw();
    }
}
