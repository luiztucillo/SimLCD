#include "Ers.h"

void Ers::begin(MCUFRIEND_kbv tft)
{
    this->tft = tft;
    ersBar.begin(tft, 20, SCREEN_H - 50, SCREEN_W - 54, 50, BACKGROUND, MAGENTA, ERS);
    curBatteryLevelPercentage = 100;
    clear();
}

void Ers::clear() {
    tft.fillRect(SCREEN_W - 54, 50, SCREEN_W - 54, SCREEN_H - 50, BACKGROUND);
    tft.fillRect(SCREEN_W - 73, SCREEN_H - 5 - 7 * 6, 15, 50, BACKGROUND);
}

void Ers::update(bool exists, uint8_t batteryLevelPercentage, uint8_t level, bool kers)
{
    if (exists != this->exists) {
        this->exists = exists;

        if (!exists) {
            clear();
            return;
        } else {
            draw();
        }
    }

    if (!exists) {
        return;
    }

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
