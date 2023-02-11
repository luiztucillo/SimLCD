#include "Speed.h"

void Speed::draw()
{
    tft.setTextSize(7);

    tft.fillRect(10, 50, 120, 49, RED);

    tft.setCursor(10, 50);
    tft.setTextColor(WHITE);
    tft.print(curSpeed);
}

void Speed::begin(MCUFRIEND_kbv tft)
{
    this->tft = tft;
    draw();
}

void Speed::update(uint16_t speed)
{
    if (curSpeed != speed) {
        curSpeed = speed;
        draw();
    }
}
