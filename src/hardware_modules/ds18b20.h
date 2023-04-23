#include "utils/timer.h"

#define THERMOMETER_INTERVAL_SECONDS 5


class DS18B20 {
public:
    DS18B20(unsigned int requestsIntervalSeconds = THERMOMETER_INTERVAL_SECONDS);
    void begin();
    float getTemp();
  
private:
    Timer _requestTimer;
};
