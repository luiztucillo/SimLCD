#ifndef LED_H
#define LED_H

#include <MCUFRIEND_kbv.h>

class Led {
private:
    static const int WIDTH = 13;
    
public:
    MCUFRIEND_kbv tft;
    void begin(MCUFRIEND_kbv tft);
    int getWidth();
    void drawLed(int x, int y, uint16_t shadow, uint16_t bright, uint16_t specular, uint16_t miniShadow);
    void drawSimpleLed(int x, int y, uint16_t color);
    void drawRedLed(int x, int y);
    void drawBlueLed(int x, int y);
    void drawYellowLed(int x, int y);
    void drawOffLed(int x, int y);

};

#endif
