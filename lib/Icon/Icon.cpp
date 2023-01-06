#include <Icon.h>
#include <MCUFRIEND_kbv.h>

void IconErs::drawIcon(MCUFRIEND_kbv tft, uint16_t x, uint16_t y, uint16_t color)
{
    int offsetX = x;
    int offsetY = y;

    int line = 0;
    int column = 0;
    tft.drawPixel(offsetX + column + 1, offsetY + line, color);
    tft.drawPixel(offsetX + column + 2, offsetY + line, color);
    tft.drawPixel(offsetX + column + 3, offsetY + line, color);
    tft.drawPixel(offsetX + column + 4, offsetY + line, color);
    tft.drawPixel(offsetX + column + 5, offsetY + line, color);
    tft.drawPixel(offsetX + column + 6, offsetY + line, color);

    line = 1;
    column = 1;
    tft.drawPixel(offsetX + column + 1, offsetY + line, color);
    tft.drawPixel(offsetX + column + 2, offsetY + line, color);
    tft.drawPixel(offsetX + column + 3, offsetY + line, color);
    tft.drawPixel(offsetX + column + 4, offsetY + line, color);
    tft.drawPixel(offsetX + column + 5, offsetY + line, color);
    tft.drawPixel(offsetX + column + 6, offsetY + line, color);

    line = 2;
    column = 2;
    tft.drawPixel(offsetX + column + 1, offsetY + line, color);
    tft.drawPixel(offsetX + column + 2, offsetY + line, color);
    tft.drawPixel(offsetX + column + 3, offsetY + line, color);
    tft.drawPixel(offsetX + column + 4, offsetY + line, color);
    tft.drawPixel(offsetX + column + 5, offsetY + line, color);
    tft.drawPixel(offsetX + column + 6, offsetY + line, color);

    line = 3;
    column = 3;
    tft.drawPixel(offsetX + column + 1, offsetY + line, color);
    tft.drawPixel(offsetX + column + 2, offsetY + line, color);
    tft.drawPixel(offsetX + column + 3, offsetY + line, color);
    tft.drawPixel(offsetX + column + 4, offsetY + line, color);
    tft.drawPixel(offsetX + column + 5, offsetY + line, color);
    tft.drawPixel(offsetX + column + 6, offsetY + line, color);

    line = 4;
    column = 4;
    tft.drawPixel(offsetX + column + 1, offsetY + line, color);
    tft.drawPixel(offsetX + column + 2, offsetY + line, color);
    tft.drawPixel(offsetX + column + 3, offsetY + line, color);
    tft.drawPixel(offsetX + column + 4, offsetY + line, color);
    tft.drawPixel(offsetX + column + 5, offsetY + line, color);
    tft.drawPixel(offsetX + column + 6, offsetY + line, color);

    line = 5;
    column = 1;
    tft.drawPixel(offsetX + column + 1, offsetY + line, color);
    tft.drawPixel(offsetX + column + 2, offsetY + line, color);
    tft.drawPixel(offsetX + column + 3, offsetY + line, color);
    tft.drawPixel(offsetX + column + 4, offsetY + line, color);
    tft.drawPixel(offsetX + column + 5, offsetY + line, color);

    line = 6;
    column = 2;
    tft.drawPixel(offsetX + column + 1, offsetY + line, color);
    tft.drawPixel(offsetX + column + 2, offsetY + line, color);
    tft.drawPixel(offsetX + column + 3, offsetY + line, color);
    tft.drawPixel(offsetX + column + 4, offsetY + line, color);

    line = 7;
    column = 3;
    tft.drawPixel(offsetX + column + 1, offsetY + line, color);
    tft.drawPixel(offsetX + column + 2, offsetY + line, color);
    tft.drawPixel(offsetX + column + 3, offsetY + line, color);

    line = 8;
    column = 4;
    tft.drawPixel(offsetX + column + 1, offsetY + line, color);
    tft.drawPixel(offsetX + column + 2, offsetY + line, color);


    line = 9;
    column = 5;
    tft.drawPixel(offsetX + column + 1, offsetY + line, color);
}

void IconFuel::drawIcon(MCUFRIEND_kbv tft, uint16_t x, uint16_t y, uint16_t color)
{

}
