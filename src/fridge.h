#include "hardware_modules/ds18b20.h"


class Fridge {
public:
  Fridge();

  void perform();

  bool doorIsOpen() const;
  bool isCompressorTurnedOn() const;
  int getTemperature();
  
private:
  Timer _compressorTimer;
  DS18B20 _thermometer;
};

