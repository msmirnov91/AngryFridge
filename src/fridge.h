#include "hardware_modules/ds18b20.h"


class Fridge {
public:
    Fridge();
	void begin();

    void perform();

    bool doorIsOpen() const;
    bool isCompressorTurnedOn() const;
    float getTemperature();
  
private:
    Timer _compressorTimer;
    DS18B20 _thermometer;
};
