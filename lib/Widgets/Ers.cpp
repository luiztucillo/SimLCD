#include "Ers.h"

void Ers::begin(MCUFRIEND_kbv tft)
{
    this->tft = tft;
    ersBar.begin(tft, 0, 100, 20, SCREEN_H - 50, SCREEN_W - 54, 50, BACKGROUND, MAGENTA, ERS);
    curBatteryLevelPercentage = 100;
    draw();
}

void Ers::update(uint8_t batteryLevelPercentage, uint8_t level, bool kers)
{
    if (curBatteryLevelPercentage != batteryLevelPercentage || level != curLevel || kers != pressingKers) {
        curBatteryLevelPercentage = batteryLevelPercentage;
        curLevel = level;
        pressingKers = kers;
        draw();
    }
}


void Ers::draw() {
    ersBar.update(curBatteryLevelPercentage, pressingKers ? GREEN : MAGENTA);
    for (int i = 0; i < maxLevels; i ++) {
        uint16_t color = i <= curLevel ? (pressingKers ? GREEN : MAGENTA) : GRAY;
        tft.fillRect(SCREEN_W - 73, SCREEN_H - 5 - i * 6, 15, 5, color);
    }
}
