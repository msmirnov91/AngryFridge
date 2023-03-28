#include "fridge.h"
#include "notificator.h"

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
}

