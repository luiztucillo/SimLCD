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
#include <Drs.h>

bool initializedRace = false;

Player player;

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

uint16_t curErs = 0;
uint16_t maxErs = 300;

void setup(void)
{
  game.begin();
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
  drs.begin(tft);
}

void loop(void)
{
  if (game.update())
  {
    if (!initializedRace && game.data.status > 0)
    {
      revs.begin(tft, game.data.maxRpm);
      fuel.begin(tft, game.data.maxFuel);
      if (game.hasErs) ers.begin(tft);
      initializedRace = true;
    }

    if (initializedRace)
    {
      gear.update(game.data.gear);
      revs.update(game.data.curTime);
      speed.update(game.data.speed);
      fuel.update(game.data.fuel);
      player.update(game.data.player);
      curTime.update(game.data.curTime);
      lastTime.update(game.data.lastTime);
      bestTime.update(game.data.bestTime);
      drs.update(game.hasDrs, game.drsAvailable, game.drsEnabled);
      if (game.hasErs) ers.update(game.data.ersChargePercentage, game.data.ersPowerLevel, game.kersInput > 0);
      if (game.data.status == 0) initializedRace = false;
    }
  }
}
