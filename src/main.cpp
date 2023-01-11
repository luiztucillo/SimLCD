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

struct DataLoader {
  uint16_t speed;
  uint16_t rpm;
  uint16_t gear;
  uint16_t maxRpm;
  uint16_t status;
  uint16_t fuel;
  uint16_t maxFuel;
  uint32_t curretLap;
  uint32_t lastLap;
  uint32_t bestLap;
};

DataLoader prevDataLoader = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
DataLoader curDataLoader = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

bool initializedRace = false;
int len = sizeof(DataLoader);
MCUFRIEND_kbv tft;
LedAutoColored revLeds = LedAutoColored();
Bar fuelBar = Bar();
Bar ersBar = Bar();

uint16_t curErs = 0;
uint16_t maxErs = 300;

uint16_t curFuel = 0;
uint16_t maxFuel = 300;

void gear() {
  int index = curDataLoader.gear;
  char shifts[] = {'R', 'N', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  
  tft.setTextSize(20);

  tft.fillRect(150, 50, 100, 140, BACKGROUND);

  tft.setCursor(150, 50);
  tft.setTextColor(WHITE);
  tft.print(shifts[index]);
}

void speed() {
  tft.setTextSize(6);

  tft.fillRect(10, 90, 102, 43, RED);

  tft.setCursor(10, 90);
  tft.setTextColor(WHITE);
  tft.print(curDataLoader.speed);
}

void rev() {
  tft.setTextSize(3);

  tft.fillRect(10, 50, 100, 22, BACKGROUND);
  tft.setCursor(10, 50);
  tft.setTextColor(WHITE);
  tft.print(curDataLoader.rpm);

  int offsetX = 22;
  int offsetY = 22; 
  for (int i = 0; i < 8; i ++) {
    revLeds.drawLed(offsetX, offsetY, curDataLoader.rpm);
    offsetX += revLeds.getWidth() + 13;
  }
}

void ers() {
  ersBar.update(curErs);
}

void setup(void) {
  Serial.begin(115200);

  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);
  tft.fillScreen(BACKGROUND);

  // revLeds.begin(tft, 0, 10000, 0x07E0, 0xF800);
  // fuelBar.begin(tft, 0, 10000, 20, SCREEN_H - 50, SCREEN_W - 54, 50, BACKGROUND, 0xDC40, Icon(FUEL));
  // ersBar.begin(tft, 0, 10000, 20, SCREEN_H - 50, SCREEN_W - 20 - 10, 50, BACKGROUND, 0xE01F, Icon(ERS));
}

void loop(void) {
  // SAY HELLO
  Serial.write('a');
  delay(30);

  if (Serial.available() > 0) {
    char buf[len];
    Serial.readBytes(buf, len);
    memcpy(&curDataLoader, &buf, len);

    if (!initializedRace) {
      revLeds.begin(tft, 0, curDataLoader.maxRpm, 0x07E0, 0xF800);
      fuelBar.begin(tft, 0, curDataLoader.maxFuel, 20, SCREEN_H - 50, SCREEN_W - 54, 50, BACKGROUND, 0xDC40, Icon(FUEL));
      initializedRace = true;
    }

    if (initializedRace) {
      if (curDataLoader.rpm != prevDataLoader.rpm) rev();
      if (curDataLoader.speed != prevDataLoader.speed) speed();
      if (curDataLoader.gear != prevDataLoader.gear) gear();
      if (curDataLoader.fuel != prevDataLoader.fuel) fuelBar.update(curDataLoader.fuel);
    }
    
    memcpy(&prevDataLoader, &buf, len);
  }

  delay(30);
}
