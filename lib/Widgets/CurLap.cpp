#include "CurLap.h"

void CurLap::draw()
{
  tft.fillRect(10, 110, 130, 49, BACKGROUND);

  tft.setCursor(10, 110);
  tft.setTextColor(WHITE);

  tft.setTextSize(2);
  tft.print("LAP ");
  tft.setTextSize(7);
  tft.print(curLap);
}

void CurLap::begin(MCUFRIEND_kbv tft)
{
    this->tft = tft;
    draw();
}

void CurLap::update(uint16_t lap)
{
    if (lap != curLap) {
        curLap = lap;
        draw();
    }
}
