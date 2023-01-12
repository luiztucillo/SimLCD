#include "Player.h"

void Player::setPlayer(uint8_t index)
{
    selectedPlayer = index;
}

uint8_t Player::getSelectedPlayer()
{
    return selectedPlayer;
}

char *Player::getSelectedPlayerName()
{
    return players[selectedPlayer];
}

void Player::nextPlayer()
{
    int max = sizeof(players)/sizeof(players[0]);
    int next = selectedPlayer ++;

    if (next == max) {
        next = 0;
    }

    selectedPlayer = next;
}
