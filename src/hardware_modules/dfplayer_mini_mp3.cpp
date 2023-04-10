#include "dfplayer_mini_mp3.h"
#include "pin_defines.h"

#define CLOSE_THE_DOOR_POLITE 1
#define THANK_YOU 2
#define CLOSE_THE_DOOR_NERVOUS 3
#define AT_LEAST 4
#define CLOSE_THE_DOOR_ANGRY 5
#define THATS_BETTER 6
#define HEM_ON 7
#define EIGHT_THOUSAND_VOLTS 8

#define SOUND_MUTE 0
#define SOUND_QUIET 10
#define SOUND_NORMAL 20
#define SOUND_LOUD 30


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

    _player.volume(SOUND_LOUD);  //Set volume value. From 0 to 30
    _player.play(THANK_YOU);  //Play the first mp3
}
