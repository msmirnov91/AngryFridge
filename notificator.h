#include "screen.h"


class Notificator {
public:
  Notificator();
  void begin();
  
  void onSystemLoading();
  void onLoadingEnded();
  void onSystemLoaded();

  void showTemperature(int temperature);
  void showCompressorState(bool isOn);

private:
  Screen _screen;
};


