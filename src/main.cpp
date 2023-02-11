#include <Arduino.h>
#include <MCUFRIEND_kbv.h>
#include <LedAutoColored.h>
#include <Bar.h>
#include <Gear.h>
#include <Revs.h>
#include <Speed.h>
#include <Fuel.h>
#include <Game.h>
#include <LapTime.h>
#include <Ers.h>
#include <Drs.h>
#include <CurLap.h>

MCUFRIEND_kbv tft;

// WIDGETS
Game game;
Bar ersBar = Bar();
Gear gear;
Revs revs;
Speed speed;
Fuel fuel;
Ers ers;
Drs drs;
LapTime curTime;
LapTime lastTime;
LapTime bestTime;
CurLap curLap;

void setup(void)
{
  game.begin();
  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);
  tft.fillScreen(BACKGROUND);

  gear.begin(tft);
  curLap.begin(tft);
  revs.begin(tft);
  speed.begin(tft);
  fuel.begin(tft);
  lastTime.begin(tft, 2, 10, 176, YELLOW);
  bestTime.begin(tft, 2, 10, 196, MAGENTA);
  curTime.begin(tft, 3, 10, 216, WHITE);
  drs.begin(tft);
  ers.begin(tft);
}

void loop(void)
{
  if (game.update())
  {
    gear.update(game.data.gear);
    revs.update(game.data.rpmPercentage);
    speed.update(game.data.speed);
    fuel.update(game.data.fuelPercentage);
    curTime.update(game.data.curTime);
    lastTime.update(game.data.lastTime);
    bestTime.update(game.data.bestTime);
    drs.update(game.hasDrs, game.drsAvailable, game.drsEnabled);
    curLap.update(game.data.curLap);
    ers.update(game.hasErs, game.data.ersChargePercentage, game.data.ersPowerLevel, game.kersInput > 0);
  }
}
