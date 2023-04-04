#include "hardware_modules/screen.h"
#include "hardware_modules/dfplayer_mini_mp3.h"


class Notificator {
public:
    Notificator();
    void begin();
  
    void onSystemLoading();
    void onLoadingEnded();
    void onSystemLoaded();

    void showTemperature(float temperature);
    void showCompressorState(bool isOn);

private:
    Screen _screen;
    DFPlayer _dfplayer;
};
