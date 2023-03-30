#include "fridge.h"

#define TERMOMETER_INTERVAL 5
#define COMPRESSOR_INTERVAL 300


Fridge::Fridge()
  : _termometerTimer(TERMOMETER_INTERVAL)
  , _compressorTimer(COMPRESSOR_INTERVAL)
{}

void Fridge::perform()
{
  
}

bool Fridge::doorIsOpen() const
{
  return false;
}

bool Fridge::isCompressorTurnedOn() const
{
  return false;
}

int Fridge::getTemperature()
{
  return 0;
}

