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
