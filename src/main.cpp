#include <Arduino.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <MCUFRIEND_kbv.h>
#include <LedAutoColored.h>
#include <Bar.h>

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
LedAutoColored revLeds = LedAutoColored();
Bar fuelBar = Bar();
Bar ersBar = Bar();

int curShift = -2;
uint16_t curErs = 0;
uint16_t maxErs = 300;

uint16_t curFuel = 0;
uint16_t maxFuel = 300;

uint16_t maxRev = 10000;

uint16_t curRev = 0;

uint16_t curSpeed = 0;

void setup(void) {
  Serial.begin(9600);

  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);
  tft.fillScreen(BACKGROUND);

  revLeds.begin(tft, 0, maxRev, 0x07E0, 0xF800);

  fuelBar.begin(tft, 0, maxFuel, 20, SCREEN_H - 50, SCREEN_W - 54, 50, BACKGROUND, 0xDC40);
  ersBar.begin(tft, 0, maxErs, 20, SCREEN_H - 50, SCREEN_W - 20 - 10, 50, BACKGROUND, 0xE01F);
  ersBar.setIcon(IconErs(), 0, 0, 0xFFFF);
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

void speed() {
  tft.fillRect(10, 90, 102, 43, RED);
  tft.setCursor(10, 90);
  tft.setTextColor(WHITE);
  tft.setTextSize(6);
  tft.print(curSpeed);
}

void rev() {
  int offsetX = 22;
  int offsetY = 22;

  tft.fillRect(10, 50, 76, 22, BACKGROUND);
  tft.setCursor(10, 50);
  tft.setTextColor(WHITE);
  tft.setTextSize(3);
  tft.print(curRev);

  for (int i = 0; i < 8; i ++) {
    revLeds.drawLed(offsetX, offsetY, curRev);
    offsetX += revLeds.getWidth() + 13;
  }
}

void fuel() {
  fuelBar.update(curFuel);
  // int height = SCREEN_H - spaceY;
  // int positionX = SCREEN_W - width * 2 - 14;

  // int offsetX = positionX + 5;
  // int offsetY = SCREEN_H - 20;
  // uint16_t color = RED;

  // for (int l1 = 0; l1 < 2; l1 ++) {
  //   for (int c1 = 0; c1 < 9; c1 ++) {
  //     tft.drawPixel(offsetX + c1, offsetY + l1, color);
  //   }
  // }

  // for (int l2 = 2; l2 < 5; l2 ++) {
  //   tft.drawPixel(offsetX, offsetY + l2, color);
  //   tft.drawPixel(offsetX + 1, offsetY + l2, color);
  //   tft.drawPixel(offsetX + 7, offsetY + l2, color);
  //   tft.drawPixel(offsetX + 8, offsetY + l2, color);
  // }

  // for (int l1 = 5; l1 < 13; l1 ++) {
  //   for (int c1 = 0; c1 < 9; c1 ++) {
  //     tft.drawPixel(offsetX + c1, offsetY + l1, color);
  //   }
  // }
}

void ers() {
  ersBar.update(curErs);
}

void loop(void) {
  curShift ++;
  if (curShift > 7) curShift = 0;

  curErs = curErs + 90;
  if (curErs > maxErs) curErs = 0;

  curRev += 1000;
  if (curRev >= maxRev) curRev = 0; 

  curFuel += 50;
  if (curFuel >= maxFuel) curFuel = 0; 

  curSpeed += 50;
  if (curSpeed > 400) curSpeed = 0;

  shift();
  ers();
  rev();
  speed();
  fuel();
  delay(1000);
}
