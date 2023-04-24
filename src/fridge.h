#include "hardware_modules/ds18b20.h"


class Fridge {
public:
    Fridge();
    void begin();

    void perform();

    unsigned long doorOpenSeconds() const;
    bool doorIsClosed() const;
    bool isCompressorTurnedOn() const;
    unsigned long untillCompressorTurnOn() const;
    float getTemperature();
  
private:
    void _switchCompressorState(int state);

    Timer _compressorTimer;
    Chronometer _doorChrono;
    DS18B20 _thermometer;
};
