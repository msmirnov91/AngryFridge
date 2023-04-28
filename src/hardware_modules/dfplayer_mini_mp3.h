#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>


class DFPlayer {
public:
    enum Message {
        EMPTY = 0,
        
        HI        = 1,
        BYE       = 2,
        THANK_YOU = 3,
        
        SYSTEM_LOADING = 4,
        SYSTEM_LOADED  = 5,
        HEM_ON         = 6,
        HEM_OFF        = 7,
        
        EIGHT_THOUSAND_VOLTS = 8,
        NO_MEAL_AFTER_6_PM   = 9,
        TOO_MUCH_BEER        = 10,
        
        CLOSE_THE_DOOR_POLITE  = 11,
        CLOSE_THE_DOOR_NERVOUS = 12,
        THATS_BETTER           = 13,
        CLOSE_THE_DOOR_ANGRY   = 14,
        AT_LEAST               = 15,
        
        ALARM          = 16,
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
