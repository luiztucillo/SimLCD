#include "Game.h"

void Game::updateBooleans()
{
    this->hasErs = (data.booleans & 0b1) > 0;
    this->hasDrs = (data.booleans & 0b10) > 0;
    this->kersInput = (data.booleans & 0b100) > 0;
    this->drsAvailable = (data.booleans & 0b1000) > 0;
    this->drsEnabled = (data.booleans & 0b10000) > 0;
}

void Game::begin()
{
    Serial.begin(115200);
}

bool Game::update()
{
    int len = sizeof(DataLoader);
    Serial.write(len);
    delay(10);

    if (Serial.available() > 0) {
        char buf[len];
        Serial.readBytes(buf, len);
        memcpy(&data, &buf, len);
        updateBooleans();
        delay(10);
        return true;
    }

    return false;
}
