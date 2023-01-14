#include "Gear.h"

void Gear::draw()
{
  tft.setTextSize(20);

  tft.fillRect(150, 50, 100, 140, BACKGROUND);

  tft.setCursor(150, 50);
  tft.setTextColor(WHITE);
  tft.print(gears[curGear]);
}

void Gear::begin(MCUFRIEND_kbv tft)
{
    this->tft = tft;
    draw();
}

void Gear::update(uint16_t gear)
{
    if (curGear != gear) {
        curGear = gear;
        draw();
    }
}
