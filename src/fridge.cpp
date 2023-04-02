#include "fridge.h"

#define COMPRESSOR_INTERVAL 300


Fridge::Fridge()
    : _compressorTimer(COMPRESSOR_INTERVAL)
    , _thermometer()
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
    return _thermometer.getTemp();
}
