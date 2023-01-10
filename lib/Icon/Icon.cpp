#include <Icon.h>
#include <MCUFRIEND_kbv.h>

Icon::Icon(IconType icon)
{
    this->icon = icon;
}

void Icon::drawIcon(MCUFRIEND_kbv tft, uint16_t offsetX, uint16_t offsetY)
{
    if (icon == ERS) {
        Serial.println("ERS ICON");
        drawErsIcon(tft, offsetX, offsetY);
        return;
    }

    if (icon == ERS) {
        Serial.println("FUEL ICON");
        drawFuelIcon(tft, offsetX, offsetY);
        return;
    }

    Serial.println("NO ICON");
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
    Serial.println("Draing FUEL ICON");
}
