#ifndef ERS_H
#define ERS_H

#include <stdint.h>
#include <MCUFRIEND_kbv.h>
#include <Bar.h>
#include <Game.h>

class Ers {
private:
    Bar ersBar = Bar();        
    MCUFRIEND_kbv tft;
    uint8_t curBatteryLevelPercentage = 0;
    uint8_t curLevel = 0;
    int maxLevels = 7;
    bool pressingKers = false;
    bool exists = false;
    void draw();
    
public:
    void begin(MCUFRIEND_kbv tft);
    void update(bool exists, uint8_t batteryLevelPercentage, uint8_t level, bool kers);
    void clear();
};

#endif
