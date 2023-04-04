#include "dfplayer_mini_mp3.h"
#include "pin_defines.h"


DFPlayer::DFPlayer()
    : _softwareSerial(
	    SOFTWARE_SERIAL_RX,
		SOFTWARE_SERIAL_TX
	)
    , _player()
{}

void DFPlayer::begin()
{
    _softwareSerial.begin(9600);
    Serial.begin(115200);
  
    Serial.println();
    Serial.println(F("DFRobot DFPlayer Mini Demo"));
    Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
    if (!_player.begin(_softwareSerial)) {  //Use softwareSerial to communicate with mp3.
      Serial.println(F("Unable to begin:"));
      Serial.println(F("1.Please recheck the connection!"));
      Serial.println(F("2.Please insert the SD card!"));
      while(true){
        delay(0); // Code to compatible with ESP8266 watch dog.
      }
    }
    Serial.println(F("DFPlayer Mini online."));
  
    _player.volume(30);  //Set volume value. From 0 to 30
    _player.play(1);  //Play the first mp3
}
