#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>


class DFPlayer {
public:
    DFPlayer();

    void begin();
	
	void interrupt();
  
private:
    SoftwareSerial _softwareSerial;
    DFRobotDFPlayerMini _player;
};
