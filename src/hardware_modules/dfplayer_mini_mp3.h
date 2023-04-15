#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>


class DFPlayer {
public:
    enum Message {
        EMPTY = 0,
        
        HI        = 1,
        BYE       = 2,
        THANK_YOU = 3,
        
        SYSTEM_LOADING = 10,
        SYSTEM_LOADED  = 11,
        HEM_ON         = 12,
        HEM_OFF        = 13,
        
        EIGHT_THOUSAND_VOLTS = 50,
        NO_MEAL_AFTER_6_PM   = 51,
        TOO_MUCH_BEER        = 52,
        
        CLOSE_THE_DOOR_POLITE  = 100,
        CLOSE_THE_DOOR_NERVOUS = 101,
        THATS_BETTER           = 102,
        CLOSE_THE_DOOR_ANGRY   = 103,
        AT_LEAST               = 104,
    };
    
    enum Volume {
        MUTE   = 0,
        QUIET  = 10,
        NORMAL = 20,
        LOUD   = 30,
    };
    
    DFPlayer();

    void begin();
    
    void play(Message msg, Volume volume=Volume::NORMAL);
    void playWithoutRepeats(Message msg, Volume volume=Volume::NORMAL);
  
private:
    SoftwareSerial _softwareSerial;
    DFRobotDFPlayerMini _player;
    Message _lastPlayed;
};
