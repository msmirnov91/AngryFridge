#include "hardware_modules/screen.h"
#include "hardware_modules/dfplayer_mini_mp3.h"


class Notificator {
public:
    Notificator();
    void begin();
  
    void onSystemLoading();
    void onLoadingEnded();

    void showStateBlock(float temperature, bool compressorIsOn, bool doorIsClosed);
    
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
    String _booleanStateMsg(bool value, String name, String trueState, String falseState);
    
    Screen _screen;
    DFPlayer _dfplayer;
    
    Severity _doorOpenSeverity;
    bool _shouldNotifyWhenDoorIsClosed;
};
