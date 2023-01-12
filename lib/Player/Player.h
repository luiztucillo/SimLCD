
#ifndef PLAYER_H
#define PLAYER_H

#include <stdint.h>

class Player {
private:
    char* players[5] = {"Visitante", "Américo", "Bira", "Danilo", "Luiz"};
    uint8_t selectedPlayer = 0;
public:
    void setPlayer(uint8_t index);
    uint8_t getSelectedPlayer();
    char* getSelectedPlayerName();
    void nextPlayer();
};

#endif
