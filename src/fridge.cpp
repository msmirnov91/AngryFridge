#include "fridge.h"
#include "hardware_modules/pin_defines.h"

#define COMPRESSOR_INTERVAL_SECONDS 300

#define TEMPERATURE_LOWER_BOUND 2
#define TEMPERATURE_UPPER_BOUND 6

#define COMPRESSOR_ON LOW
#define COMPRESSOR_OFF HIGH

#define LAMP_ON LOW
#define LAMP_OFF HIGH

#define DOOR_CLOSED LOW
#define DOOR_OPENED HIGH

#define DOOR_IS_CLOSED_SECONDS_THRESHOLD 1


Fridge::Fridge()
    : _compressorTimer(COMPRESSOR_INTERVAL_SECONDS)
    , _doorChrono()
    , _thermometer()
{}

void Fridge::begin()
{
    pinMode(COMPRESSOR_PIN, OUTPUT);
    digitalWrite(COMPRESSOR_PIN, COMPRESSOR_OFF);
    
    pinMode(LAMP_PIN, OUTPUT);
    digitalWrite(LAMP_PIN, LAMP_OFF);
    
    pinMode(DOOR_PIN, INPUT);

    _thermometer.begin();
}

void Fridge::perform()
{
    float temperature = getTemperature();
    if (temperature > TEMPERATURE_UPPER_BOUND && !isCompressorTurnedOn()) {
        _switchCompressorState(COMPRESSOR_ON);
    }
    else if (temperature < TEMPERATURE_LOWER_BOUND && isCompressorTurnedOn()) {
        _switchCompressorState(COMPRESSOR_OFF);
    }
    
    if (digitalRead(DOOR_PIN) == DOOR_OPENED) {
        digitalWrite(LAMP_PIN, LAMP_ON);
    }
    else {
        digitalWrite(LAMP_PIN, LAMP_OFF);
        _doorChrono.reset();
    }
}

unsigned long Fridge::doorOpenSeconds() const
{
    return _doorChrono.secondsPassed();
}

bool Fridge::doorIsClosed() const
{
    return doorOpenSeconds() <= DOOR_IS_CLOSED_SECONDS_THRESHOLD;
}

bool Fridge::isCompressorTurnedOn() const
{
    return digitalRead(COMPRESSOR_PIN) == COMPRESSOR_ON;
}

unsigned long Fridge::untillCompressorTurnOn() const
{
    if (isCompressorTurnedOn()) {
        return 0;
    }
    
    return _compressorTimer.secondsUntilReady();
}

float Fridge::getTemperature()
{
    return _thermometer.getTemp();
}

void Fridge::_switchCompressorState(int state)
{
    if (state == COMPRESSOR_ON && !_compressorTimer.ready()) {
        return;
    }
    digitalWrite(COMPRESSOR_PIN, state);
}
