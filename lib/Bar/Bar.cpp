#include <Bar.h>
#include <Color.h>
#include <Icon.h>

void Bar::begin(MCUFRIEND_kbv tft, uint16_t width, 
    uint16_t height, uint16_t positionX, uint16_t positionY, uint16_t backgroundColor, uint16_t foregroundColor, IconType iconType) {
    this->tft = tft;
    this->width = width;
    this->height = height;
    this->positionX = positionX;
    this->positionY = positionY;
    this->backgroundColor = backgroundColor;
    this->foregroundColor = foregroundColor;
    this->iconType = iconType;
}

void Bar::draw(uint8_t value, uint16_t color) {
    int finalPositionX = positionX + 1;
    int finalPositionY = positionY + 1;
    int finalWidth = width - 2;
    int finalHeight = height - 2;

    int filledHeight = value * finalHeight / 100;
    int unfilledHeight = finalHeight - filledHeight;

    tft.fillRect(positionX, positionY, width, height, WHITE);
    tft.fillRect(finalPositionX, finalPositionY, finalWidth, unfilledHeight, BACKGROUND);
    tft.fillRect(finalPositionX, finalPositionY + finalHeight - filledHeight, finalWidth, filledHeight, color);

    Icon icon = Icon();
    icon.drawIcon(iconType, tft, positionX, positionY + height);
}

void Bar::update(uint8_t value) {
    draw(value, foregroundColor);
}

void Bar::update(uint8_t value, uint16_t color) {
    draw(value, color);
}
