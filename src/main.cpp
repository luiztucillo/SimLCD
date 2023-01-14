#include <Arduino.h>
#include <MCUFRIEND_kbv.h>
#include <LedAutoColored.h>
#include <Bar.h>
#include <Player.h>
#include <Gear.h>
#include <Revs.h>
#include <Speed.h>
#include <Fuel.h>
#include <Game.h>
#include <LapTime.h>
#include <Ers.h>

struct DataLoader
{
  uint16_t speed = 0;
  uint16_t rpm = 0;
  uint16_t gear = 0;
  uint16_t maxRpm = 0;
  uint16_t status = 0;
  uint16_t fuel = 0;
  uint16_t maxFuel = 0;
  uint8_t player = 0;
  uint32_t curTime = 0;
  uint32_t lastTime = 0;
  uint32_t bestTime = 0;
  uint8_t hasErs = 0;
  uint8_t ersPowerLevel = 0;
  uint8_t ersChargePercentage = 0;
  uint8_t kersInput = 0;
};

int len = sizeof(DataLoader);

bool initializedRace = false;

Player player;

DataLoader curDataLoader;
MCUFRIEND_kbv tft;

// WIDGETS
Bar ersBar = Bar();
Gear gear;
Revs revs;
Speed speed;
Fuel fuel;
Ers ers;
LapTime curTime;
LapTime lastTime;
LapTime bestTime;

uint16_t curErs = 0;
uint16_t maxErs = 300;

void setup(void)
{
  Serial.begin(115200);

  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);
  tft.fillScreen(BACKGROUND);

  gear.begin(tft);
  revs.begin(tft, 1000);
  speed.begin(tft);
  fuel.begin(tft, 0);
  player.begin(tft);
  lastTime.begin(tft, 2, 10, 176, YELLOW);
  bestTime.begin(tft, 2, 10, 196, MAGENTA);
  curTime.begin(tft, 3, 10, 216, WHITE);
}

void loop(void)
{
  Serial.write(len);
  delay(10);

  if (Serial.available() > 0)
  {
    char buf[len];
    Serial.readBytes(buf, len);
    memcpy(&curDataLoader, &buf, len);
    delay(30);

    if (!initializedRace && curDataLoader.status > 0)
    {
      revs.begin(tft, curDataLoader.maxRpm);
      fuel.begin(tft, curDataLoader.maxFuel);

      if (curDataLoader.hasErs)
      {
        ers.begin(tft);
      }

      initializedRace = true;
    }

    if (initializedRace)
    {
      gear.update(curDataLoader.gear);
      revs.update(curDataLoader.rpm);
      speed.update(curDataLoader.speed);
      fuel.update(curDataLoader.fuel);
      player.update(curDataLoader.player);
      curTime.update(curDataLoader.curTime);
      lastTime.update(curDataLoader.lastTime);
      bestTime.update(curDataLoader.bestTime);
      ers.update(curDataLoader.ersChargePercentage, curDataLoader.ersPowerLevel, curDataLoader.kersInput > 0);

      if (curDataLoader.status == 0) {
        initializedRace = false;
      }
    }
  }

  delay(30);
}
