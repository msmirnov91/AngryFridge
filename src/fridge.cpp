#include "fridge.h"
#include "hardware_modules/pin_defines.h"

#define COMPRESSOR_INTERVAL 300

#define TEMPERATURE_LOWER_BOUND 0
#define TEMPERATURE_UPPER_BOUND 10


Fridge::Fridge()
    : _compressorTimer(COMPRESSOR_INTERVAL)
    , _thermometer()
{}

void Fridge::begin()
{
    pinMode(COMPRESSOR_PIN, OUTPUT);
    pinMode(DOOR_PIN, INPUT);

    _thermometer.begin();
}

void Fridge::perform()
{
    float temperature = getTemperature();
    if (temperature > TEMPERATURE_UPPER_BOUND && !isCompressorTurnedOn()) {
        digitalWrite(COMPRESSOR_PIN, HIGH);
    }
    else if (temperature < TEMPERATURE_LOWER_BOUND && isCompressorTurnedOn()) {
        digitalWrite(COMPRESSOR_PIN, LOW);
    }
}

unsigned long Fridge::doorOpenTime() const
{
    return 0;
}

bool Fridge::isCompressorTurnedOn() const
{
    return digitalRead(DOOR_PIN);
}

float Fridge::getTemperature()
{
    return _thermometer.getTemp();
}
