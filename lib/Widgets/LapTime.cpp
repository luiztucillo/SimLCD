#include "LapTime.h"

void LapTime::draw()
{
    tft.setTextSize(size);
    tft.fillRect(x, y, size * 60, size * 10, BACKGROUND);
    tft.setCursor(x, y);
    tft.setTextColor(color);

    char str[] = "00:00:000";
    format(str);
    tft.print(str);
}

void LapTime::format(char* buffer)
{
    uint8_t seconds = curTime / 1000 % 60;
	uint8_t minutes = curTime / 60000;
	uint16_t rest = curTime % 1000;

    char s[] = "00";
	sprintf(s, "%02d", seconds);

    char m[] = "00";
	sprintf(m, "%02d", minutes);

    char r[] = "000";
	sprintf(r, "%03d", rest);

    buffer[0] = m[0];
    buffer[1] = m[1];
    buffer[2] = ':';
    buffer[3] = s[0];
    buffer[4] = s[1];
    buffer[5] = ':';
    buffer[6] = r[0];
    buffer[7] = r[1];
    buffer[8] = r[2];
}

void LapTime::begin(MCUFRIEND_kbv tft, uint16_t size, uint16_t x, uint16_t y, uint16_t color)
{
    this->tft = tft;
    this->size = size;
    this->x = x;
    this->y = y;
    this->color = color;
    draw();
}

void LapTime::update(uint32_t time)
{
    if (time != curTime) {
        curTime = time;
        draw();
    }
}
