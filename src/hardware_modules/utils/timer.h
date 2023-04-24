#include "chrono.h"


class Timer {
public:
    Timer(unsigned int intervalSeconds);
    bool ready();
    unsigned long secondsUntilReady() const;

private:
    Chronometer _chrono;
    const unsigned long _interval;
};
