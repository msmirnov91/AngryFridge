#include "src/fridge.h"
#include "src/notificator.h"


Notificator notificator;
Fridge fridge;

void setup()
{
    notificator.begin();
    fridge.begin();

    notificator.onSystemLoading();
    delay(2000);
    notificator.onLoadingEnded();
}

void loop()
{
    notificator.onSystemLoaded();
    fridge.perform();

    notificator.showTemperature(fridge.getTemperature());
    notificator.showCompressorState(fridge.isCompressorTurnedOn());
}

