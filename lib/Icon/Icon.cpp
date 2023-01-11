#include <Icon.h>
#include <MCUFRIEND_kbv.h>

void Icon::drawIcon(IconType type, MCUFRIEND_kbv tft, uint16_t offsetX, uint16_t offsetY)
{
    if (type == ERS)
    {
        drawErsIcon(tft, offsetX, offsetY);
        return;
    }

    if (type == FUEL)
    {
        drawFuelIcon(tft, offsetX, offsetY);
        return;
    }
}

void Icon::drawErsIcon(MCUFRIEND_kbv tft, uint16_t offsetX, uint16_t offsetY)
{
    uint16_t color = 0xFFFF;

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

void Icon::drawFuelIcon(MCUFRIEND_kbv tft, uint16_t offsetX, uint16_t offsetY)
{
    offsetX = offsetX + 5;
    offsetY = offsetY - 20;
    uint16_t color = 0xF100;

    for (int l1 = 0; l1 < 2; l1++)
    {
        for (int c1 = 0; c1 < 9; c1++)
        {
            tft.drawPixel(offsetX + c1, offsetY + l1, color);
        }
    }

    for (int l2 = 2; l2 < 5; l2++)
    {
        tft.drawPixel(offsetX, offsetY + l2, color);
        tft.drawPixel(offsetX + 1, offsetY + l2, color);
        tft.drawPixel(offsetX + 7, offsetY + l2, color);
        tft.drawPixel(offsetX + 8, offsetY + l2, color);
    }

    for (int l1 = 5; l1 < 13; l1++)
    {
        for (int c1 = 0; c1 < 9; c1++)
        {
            tft.drawPixel(offsetX + c1, offsetY + l1, color);
        }
    }
}
