#include "utils/timer.h"

#define THERMOMETER_INTERVAL 5


class DS18B20 {
public:
    DS18B20(unsigned int requestsInterval = THERMOMETER_INTERVAL);
    void begin();
    int getTemp();
  
private:
    Timer _requestTimer;
};
