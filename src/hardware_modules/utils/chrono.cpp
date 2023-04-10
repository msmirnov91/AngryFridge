#include "chrono.h"

#if (ARDUINO >= 100)
    #include <Arduino.h>
#else
    #include <WProgram.h>
    #include <pins_arduino.h>
#endif


Chronometer::Chronometer()
{
    reset();
}

void Chronometer::reset()
{
    _startTime = millis();
}
    
unsigned long Chronometer::secondsPassed() const
{
    return (millis() - _startTime) / 1000;
}
