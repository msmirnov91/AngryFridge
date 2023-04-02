#include "ds18b20.h"

#include <microDS18B20.h>
MicroDS18B20<4> sensor;


DS18B20::DS18B20(unsigned int requestsInterval)
    : _requestTimer(requestsInterval)
{
}

void DS18B20::begin()
{
    sensor.requestTemp();
    delay(1000);
}

int DS18B20::getTemp()  // TODO: should be int16_t!!!
{
    if (_requestTimer.ready()) {
        sensor.requestTemp();
    }
    return sensor.getTempInt();
}
  