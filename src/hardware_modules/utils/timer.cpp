#include "timer.h"


Timer::Timer(unsigned int intervalSeconds)
    : _chrono()
    , _interval(intervalSeconds)
{
}

bool Timer::ready()
{
    if (_chrono.secondsPassed() > _interval) {
        _chrono.reset();
        return true;
    }

    return false;
}

unsigned long Timer::secondsUntilReady() const
{
    unsigned long passed = _chrono.secondsPassed();
    return _interval >= passed ? _interval - passed : 0;
}
