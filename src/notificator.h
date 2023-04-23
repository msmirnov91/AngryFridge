#include "hardware_modules/screen.h"
#include "hardware_modules/dfplayer_mini_mp3.h"


class Notificator {
public:
    Notificator();
    void begin();
  
    void onSystemLoading();
    void onLoadingEnded();

    void showTemperature(float temperature);
    void showCompressorState(bool isOn);
    
    enum Severity {
        NONE,
        POLITE,
        NERVOUS,
        ANGRY,
        HEM,
    };
    
    void askCloseTheDoor(Severity sev);
    bool shouldNotifyWhenDoorIsClosed() const;
    void notifyDoorIsClosed();

private:
    Screen _screen;
    DFPlayer _dfplayer;
    
    Severity _doorOpenSeverity;
    bool _shouldNotifyWhenDoorIsClosed;
};
