#include "fridge.h"

#define COMPRESSOR_INTERVAL 300


Fridge::Fridge()
    : _compressorTimer(COMPRESSOR_INTERVAL)
    , _thermometer()
{}

void Fridge::begin()
{
	_thermometer.begin();
}

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

float Fridge::getTemperature()
{
    return _thermometer.getTemp();
}
