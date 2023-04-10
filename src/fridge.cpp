#include "fridge.h"
#include "hardware_modules/pin_defines.h"

#define COMPRESSOR_INTERVAL 300

#define TEMPERATURE_LOWER_BOUND 0
#define TEMPERATURE_UPPER_BOUND 10


Fridge::Fridge()
    : _compressorTimer(COMPRESSOR_INTERVAL)
    , _doorChrono()
    , _thermometer()
{}

void Fridge::begin()
{
    pinMode(COMPRESSOR_PIN, OUTPUT);
    pinMode(DOOR_PIN, INPUT);

    _thermometer.begin();
    if (_thermometer.getTemp() > TEMPERATURE_UPPER_BOUND) {
        digitalWrite(COMPRESSOR_PIN, HIGH);
    }
}

void Fridge::perform()
{
    float temperature = getTemperature();
    if (temperature > TEMPERATURE_UPPER_BOUND && !isCompressorTurnedOn()) {
        _switchCompressorState(HIGH);
    }
    else if (temperature < TEMPERATURE_LOWER_BOUND && isCompressorTurnedOn()) {
        _switchCompressorState(LOW);
    }
    
    if (digitalRead(DOOR_PIN) == LOW) {
        _doorChrono.reset();
    }
}

unsigned long Fridge::doorOpenTime() const
{
    return _doorChrono.secondsPassed();
}

bool Fridge::isCompressorTurnedOn() const
{
    return digitalRead(COMPRESSOR_PIN) == HIGH;
}

float Fridge::getTemperature()
{
    return _thermometer.getTemp();
}

void Fridge::_switchCompressorState(int state)
{
    if (digitalRead(COMPRESSOR_PIN) != state && _compressorTimer.ready()) {
        digitalWrite(COMPRESSOR_PIN, state);
    }
}
