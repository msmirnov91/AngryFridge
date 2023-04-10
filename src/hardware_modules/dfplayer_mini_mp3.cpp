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

    if (!_player.begin(_softwareSerial)) {
		// handle the error
    }

    _player.volume(30);  //Set volume value. From 0 to 30
    _player.play(1);  //Play the first mp3
}
