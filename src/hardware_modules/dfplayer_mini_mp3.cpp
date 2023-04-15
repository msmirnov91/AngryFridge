#include "dfplayer_mini_mp3.h"
#include "pin_defines.h"


DFPlayer::DFPlayer()
    : _softwareSerial(
        SOFTWARE_SERIAL_RX,
        SOFTWARE_SERIAL_TX
    )
    , _player()
    , _lastPlayed(DFPlayer::Message::EMPTY)
{}

void DFPlayer::begin()
{
    _softwareSerial.begin(9600);

    if (!_player.begin(_softwareSerial)) {
        // handle the error
    }
}

void DFPlayer::play(DFPlayer::Message msg, DFPlayer::Volume volume)
{
    int vol = int(volume);
    if (vol > int(DFPlayer::Volume::LOUD)) {
        vol = int(DFPlayer::Volume::LOUD);
    }
    
    _player.stop();
    _player.volume(vol);
    _player.play(int(msg));
    _lastPlayed = msg;
}

void DFPlayer::playWithoutRepeats(DFPlayer::Message msg, DFPlayer::Volume volume)
{
    if (msg != _lastPlayed) {
        play(msg, volume);
    }
}
