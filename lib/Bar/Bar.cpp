#include <Bar.h>
#include <Color.h>

void Bar::begin(MCUFRIEND_kbv tft, uint16_t minValue, uint16_t maxValue, uint16_t width, uint16_t height, uint16_t positionX, uint16_t positionY, uint16_t backgroundColor, uint16_t foregroundColor) {
    this->tft = tft;
    this->minValue = minValue;
    this->maxValue = maxValue;
    this->width = width;
    this->height = height;
    this->positionX = positionX;
    this->positionY = positionY;
    this->backgroundColor = backgroundColor;
    this->foregroundColor = foregroundColor;
}


void Bar::setIcon(Icon icon, uint16_t iconX, uint16_t iconY, uint16_t iconColor)
{
    this->icon = icon;
    this->iconX = iconX;
    this->iconY = iconY;
    this->iconColor = iconColor;
}

void Bar::update(uint16_t value) {
    float fraction = ((float) (100 * value / (maxValue - minValue))) / 100;
    int current = (height - 2) * fraction;

    tft.drawRect(positionX, positionY, width, height, 0xFFFF);
    tft.fillRect(positionX + 1, positionY + 1, width - 2, height - 2, backgroundColor);
    tft.fillRect(positionX + 1, positionY + height - current - 1, width - 2, current, foregroundColor);

    icon.drawIcon(tft, positionX + iconX, positionY + iconY, iconColor);
}
