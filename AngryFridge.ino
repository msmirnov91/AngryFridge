#include "src/fridge.h"
#include "notificator.h"


Notificator notificator;
Fridge fridge;

void setup()
{
  notificator.begin();

  notificator.onSystemLoading();
  delay(5000);
  notificator.onLoadingEnded();
}

void loop()
{
  notificator.onSystemLoaded();
  fridge.perform();

  notificator.showTemperature(fridge.getTemperature());
  notificator.showCompressorState(fridge.isCompressorTurnedOn());
}

