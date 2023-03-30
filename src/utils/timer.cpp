#include "timer.h"


Timer::Timer(unsigned int intervalSeconds)
    : _interval(intervalSeconds * 1000)
    , _lastReadyTime(0)
{
}

bool Timer::ready()
{
    unsigned long now = millis();
    unsigned long passed = now - _lastReadyTime;

    bool isReady = passed > _interval;
    if (isReady) {
        _lastReadyTime = now;
    }

    return isReady;
}
