#include "utils/timer.h"


class Fridge {
public:
  Fridge();

  void perform();

  bool doorIsOpen() const;
  bool isCompressorTurnedOn() const;
  int getTemperature();
  
private:
  Timer _termometerTimer;
  Timer _compressorTimer;
};

