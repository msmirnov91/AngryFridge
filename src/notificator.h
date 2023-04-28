#include "hardware_modules/screen.h"
#include "hardware_modules/dfplayer_mini_mp3.h"
#include "hardware_modules/utils/timer.h"


class Notificator {
public:
    Notificator();
    void begin();
  
    void onSystemLoading();
    void onLoadingEnded();

    void showStateBlock(
        float temperature,
        bool compressorIsOn,
        unsigned long untillCompressorTurnOn,
        bool doorIsClosed
    );
    
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
    
    bool isHEMMode() const;
    void notifyHEMMode();
    
    void notifyEightThousandVolts();
    void alarm();

private:
    String _booleanValueMsg(bool value, String name, String trueState, String falseState);
    String _untillCompressorTurnOnMsg(unsigned long untillCompressorTurnOn);
    void _printStateBlockMsg(uint8_t lineNumber, String msg);
    
    void _switchHEMMode(bool isOn);
    
    Screen _screen;
    DFPlayer _dfplayer;
    
    Severity _doorOpenSeverity;
    bool _shouldNotifyWhenDoorIsClosed;
    
    bool _isHEMMode;
    
    Timer _alarmTimer;
};
