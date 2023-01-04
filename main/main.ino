#include <Adafruit_GFX.h>    // Core graphics library
#include <MCUFRIEND_kbv.h>

#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define GRAY    0x7BEF
#define BACKGROUND 0x0101

#define SCREEN_W 320
#define SCREEN_H 240

MCUFRIEND_kbv tft;

int curShift = -2;
int curErs = 0;
int maxErs = 300;
int maxRev = 10000;
int curRev = 0;
int curSpeed = 0;

void setup(void) {
  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);
  tft.fillScreen(BACKGROUND);
}

void loop(void) {
  curShift ++;
  if (curShift > 7) curShift = 0;

  curErs = curErs + 90;
  if (curErs > maxErs) curErs = 0;

  curRev += 1000;
  if (curRev >= maxRev) curRev = 0; 

  curSpeed += 50;
  if (curSpeed > 400) curSpeed = 0;

  shift();
  ers();
  rev();
  speed();
  fuel();
  delay(1000);
}

void speed() {
  tft.fillRect(10, 90, 102, 43, RED);
  tft.setCursor(10, 90);
  tft.setTextColor(WHITE);
  tft.setTextSize(6);
  tft.print(curSpeed);
}

void drawLed(int x, int y, uint16_t shadow, uint16_t bright, uint16_t specular, uint16_t miniShadow) {
  tft.fillCircle(x, y, 13, specular);
  tft.fillCircle(x, y, 12, GRAY);
  tft.fillCircle(x, y, 11, 0x52AA);
  tft.fillCircle(x, y, 10, shadow); // shadow
  tft.fillCircle(x, y, 8, bright); // bright 
  tft.fillCircle(x - 4, y - 4, 5, specular); //specular
  tft.fillCircle(x + 5, y + 5, 4, miniShadow); // mini-shadow
  tft.fillCircle(x, y, 6, bright); // bright 
}

void drawRedLed(int x, int y) {
  drawLed(x, y, 0xA082, 0xF800, 0xFACB, 0x9041);
}

void drawBlueLed(int x, int y) {
  drawLed(x, y, 0x0215, 0x1B7E,  0x447F, 0x014D);
}

void drawYellowLed(int x, int y) {
  drawLed(x, y, 0xBC40, 0xD4C0,  0xFE25, 0x8B20);
}

void drawOffLed(int x, int y) {
  drawLed(x, y, 0x4228, 0x630C,  0x8C51, 0x4A69);
}

void rev() {
  int offsetX = 22;
  int offsetY = 22;
  int space = 39;
  float revPerc = 100 * (curRev / 1000) / (maxRev / 1000);

  tft.fillRect(10, 50, 76, 22, BACKGROUND);
  tft.setCursor(10, 50);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(curRev);

  if (revPerc >= 50) {
    drawBlueLed(offsetX, offsetY);
  } else {
    drawOffLed(offsetX, offsetY);
  }

  if (revPerc >= 60) {
    drawBlueLed(offsetX += space, offsetY);
  } else {
    drawOffLed(offsetX += space, offsetY);
  }

  if (revPerc >= 65) {
    drawYellowLed(offsetX += space, offsetY);
  } else {
    drawOffLed(offsetX += space, offsetY);
  }

  if (revPerc >= 70) {
    drawYellowLed(offsetX += space, offsetY);
  } else {
    drawOffLed(offsetX += space, offsetY);
  }

  if (revPerc >= 75) {
    drawYellowLed(offsetX += space, offsetY);
  } else {
    drawOffLed(offsetX += space, offsetY);
  }

  if (revPerc >= 80) {
    drawRedLed(offsetX += space, offsetY);
  } else {
    drawOffLed(offsetX += space, offsetY);
  }

  if (revPerc >= 85) {
    drawRedLed(offsetX += space, offsetY);
  } else {
    drawOffLed(offsetX += space, offsetY);
  }

  if (revPerc >= 90) {
    drawRedLed(offsetX += space, offsetY);
  } else {
    drawOffLed(offsetX += space, offsetY);
  }
}

void shift() {
  int size = 20;
  int x = 150;
  int y = 50;

  int index = curShift < -1 || curShift > 10 ? 0 : curShift + 1;
  char shifts[] = {'R', 'N', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

  tft.fillRect(x, y, 100, 140, BACKGROUND);
  tft.setCursor(x, y);
  tft.setTextColor(WHITE);
  tft.setTextSize(size);
  tft.print(shifts[index]);
  delay(100);
}

void fuel() {
  int curPercentage = 100 * curErs / maxErs;
  int spaceY = 50;
  int width = 20;
  int height = SCREEN_H - spaceY;
  int positionX = SCREEN_W - width * 2 - 14;
  
  int full = height - 2;
  int current = full * curPercentage / 100;

  tft.drawRect(positionX, spaceY, width, height, WHITE);
  tft.fillRect(positionX + 1, spaceY + 1, width - 2, height - 2, BACKGROUND);
  tft.fillRect(positionX + 1, spaceY + height - current - 1, width - 2, current, YELLOW);

  int offsetX = positionX + 5;
  int offsetY = SCREEN_H - 20;
  uint16_t color = RED;

  for (int l1 = 0; l1 < 2; l1 ++) {
    for (int c1 = 0; c1 < 9; c1 ++) {
      tft.drawPixel(offsetX + c1, offsetY + l1, color);
    }
  }

  for (int l2 = 2; l2 < 5; l2 ++) {
    tft.drawPixel(offsetX, offsetY + l2, color);
    tft.drawPixel(offsetX + 1, offsetY + l2, color);
    tft.drawPixel(offsetX + 7, offsetY + l2, color);
    tft.drawPixel(offsetX + 8, offsetY + l2, color);
  }

  for (int l1 = 5; l1 < 13; l1 ++) {
    for (int c1 = 0; c1 < 9; c1 ++) {
      tft.drawPixel(offsetX + c1, offsetY + l1, color);
    }
  }
}

void ers() {
  int curPercentage = 100 * curErs / maxErs;
  int spaceY = 50;
  int width = 20;
  int height = SCREEN_H - spaceY;
  int positionX = SCREEN_W - width - 10;
  
  int full = height - 2;
  int current = full * curPercentage / 100;

  tft.drawRect(positionX, spaceY, width, height, WHITE);
  tft.fillRect(positionX + 1, spaceY + 1, width - 2, height - 2, BACKGROUND);
  tft.fillRect(positionX + 1, spaceY + height - current - 1, width - 2, current, MAGENTA);

  int offsetX = positionX + 4;
  int offsetY = SCREEN_H - 17;

  int line = 0;
  int column = 0;
  tft.drawPixel(offsetX + column + 1, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 2, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 3, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 4, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 5, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 6, offsetY + line, WHITE);

  line = 1;
  column = 1;
  tft.drawPixel(offsetX + column + 1, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 2, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 3, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 4, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 5, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 6, offsetY + line, WHITE);

  line = 2;
  column = 2;
  tft.drawPixel(offsetX + column + 1, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 2, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 3, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 4, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 5, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 6, offsetY + line, WHITE);

  line = 3;
  column = 3;
  tft.drawPixel(offsetX + column + 1, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 2, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 3, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 4, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 5, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 6, offsetY + line, WHITE);

  line = 4;
  column = 4;
  tft.drawPixel(offsetX + column + 1, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 2, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 3, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 4, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 5, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 6, offsetY + line, WHITE);

  line = 5;
  column = 1;
  tft.drawPixel(offsetX + column + 1, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 2, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 3, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 4, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 5, offsetY + line, WHITE);

  line = 6;
  column = 2;
  tft.drawPixel(offsetX + column + 1, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 2, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 3, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 4, offsetY + line, WHITE);

  line = 7;
  column = 3;
  tft.drawPixel(offsetX + column + 1, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 2, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 3, offsetY + line, WHITE);

  line = 8;
  column = 4;
  tft.drawPixel(offsetX + column + 1, offsetY + line, WHITE);
  tft.drawPixel(offsetX + column + 2, offsetY + line, WHITE);

  
  line = 9;
  column = 5;
  tft.drawPixel(offsetX + column + 1, offsetY + line, WHITE);
}
