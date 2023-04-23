#include "src/fridge.h"
#include "src/notificator.h"

#define POLITE_ASK_THRESHOLD 10
#define NERVOUS_ASK_THRESHOLD 20
#define ANGRY_ASK_THRESHOLD 30
#define HEM_THRESHOLD 30


Notificator notificator;
Fridge fridge;

void setup()
{
    notificator.begin();
    notificator.onSystemLoading();
    fridge.begin();
    notificator.onLoadingEnded();
}

void loop()
{
    fridge.perform();

    notificator.showTemperature(fridge.getTemperature());
    notificator.showCompressorState(fridge.isCompressorTurnedOn());

    if (!fridge.doorIsClosed()) {
        unsigned long doorOpenSeconds = fridge.doorOpenSeconds();
        Notificator::Severity sev = Notificator::Severity::NONE;
        
        if (doorOpenSeconds >= POLITE_ASK_THRESHOLD && doorOpenSeconds < NERVOUS_ASK_THRESHOLD) {
            sev = Notificator::Severity::POLITE;
        }
        if (doorOpenSeconds >= NERVOUS_ASK_THRESHOLD && doorOpenSeconds < ANGRY_ASK_THRESHOLD) {
            sev = Notificator::Severity::NERVOUS;
        }
        if (doorOpenSeconds >= ANGRY_ASK_THRESHOLD && doorOpenSeconds < HEM_THRESHOLD) {
            sev = Notificator::Severity::ANGRY;
        }
        if (doorOpenSeconds >= HEM_THRESHOLD) {
            sev = Notificator::Severity::HEM;
        }

        notificator.askCloseTheDoor(sev);
    }

    if (fridge.doorIsClosed() && notificator.shouldNotifyWhenDoorIsClosed()) {
        notificator.notifyDoorIsClosed();
    }
}

