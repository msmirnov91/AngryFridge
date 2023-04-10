#include "hardware_modules/ds18b20.h"


class Fridge {
public:
    Fridge();
    void begin();

    void perform();

    unsigned long doorOpenTime() const;
    bool isCompressorTurnedOn() const;
    float getTemperature();
  
private:
    void _switchCompressorState(int state);

    Timer _compressorTimer;
    Chronometer _doorChrono;
    DS18B20 _thermometer;
};
