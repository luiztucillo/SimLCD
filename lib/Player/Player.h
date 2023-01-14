
#ifndef PLAYER_H
#define PLAYER_H

#include <stdint.h>
#include <MCUFRIEND_kbv.h>
#include <Game.h>

class Player {
private:
    MCUFRIEND_kbv tft;
    char* players[5] = {"Visitante", "Américo", "Bira", "Danilo", "Luiz"};
    uint8_t selectedPlayer = 0;
    void draw();
public:
    void begin(MCUFRIEND_kbv tft);
    void update(uint8_t playerId);
    uint8_t getSelectedPlayer();
    char* getSelectedPlayerName();
};

#endif
