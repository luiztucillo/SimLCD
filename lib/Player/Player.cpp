#include "Player.h"

void Player::draw()
{
    tft.setTextSize(2);
    tft.fillRect(10, 150, 120, 43, BACKGROUND);
    tft.setCursor(10, 150);
    tft.setTextColor(WHITE);
    tft.print(getSelectedPlayerName());
}

void Player::begin(MCUFRIEND_kbv tft)
{
    this->tft = tft;
    draw();
}

void Player::update(uint8_t playerId)
{
    if (playerId != selectedPlayer) {
        selectedPlayer = playerId;
        draw();
    }
}

uint8_t Player::getSelectedPlayer()
{
    return selectedPlayer;
}

char *Player::getSelectedPlayerName()
{
    return players[selectedPlayer];
}
