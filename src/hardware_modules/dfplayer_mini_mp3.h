#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>


class DFPlayer {
public:
    DFPlayer();

    void begin();
  
private:
    SoftwareSerial _softwareSerial;
    DFRobotDFPlayerMini _player;
};
