#include "Drs.h"

void Drs::draw()
{
    if (!exists)
    {
        return;
    }

    uint16_t color;

    if (available && !enabled)
    {
        color = YELLOW;
    }
    else if (enabled)
    {
        color = GREEN;
    }
    else
    {
        color = GRAY;
    }

    tft.fillRoundRect(SCREEN_W - 130, SCREEN_H - 40, 50, 40, 2, color);

    tft.setTextSize(2);
    tft.setCursor(SCREEN_W - 122, SCREEN_H - 27);
    tft.setTextColor(BACKGROUND);
    tft.print("DRS");
}

void Drs::begin(MCUFRIEND_kbv tft)
{
    this->tft = tft;
}

void Drs::update(bool exists, bool available, bool enabled)
{
    if (exists != this->exists || this->available != available || this->enabled != enabled)
    {
        this->exists = exists;
        this->available = available;
        this->enabled = enabled;
        draw();
    }
}
