#include "notificator.h"

#define UPPER_STATE_BLOCK_BORDER 80
#define LEFT_STATE_BLOCK_BORDER 70


Notificator::Notificator()
    : _screen()
    , _dfplayer()
    , _doorOpenSeverity(Notificator::Severity::NONE)
    , _shouldNotifyWhenDoorIsClosed(false)
{}

void Notificator::begin()
{
    _screen.begin();
    _dfplayer.begin();
}

void Notificator::onSystemLoading()
{
    _dfplayer.playWithoutRepeats(DFPlayer::Message::SYSTEM_LOADING);
    _screen.printText(55, 5, "Загрузка системы...", ILI9341_WHITE, true);
    _screen.printText(53, 110, "ANGRY FRIDGE", ILI9341_RED, true, Screen::TextSize::LARGE);
    _screen.printText(4, 220, "Powered by DCP Electronics", ILI9341_GREEN, true);
    delay(1000);
}

void Notificator::onLoadingEnded()
{
    _dfplayer.playWithoutRepeats(DFPlayer::Message::SYSTEM_LOADED);
    _screen.printText(55, 40, "СИСТЕМА ЗАГРУЖЕНА", ILI9341_GREEN, true);
    delay(1000);
    _screen.fillScreen(ILI9341_BLACK);
}

void Notificator::showStateBlock(float temperature, bool compressorIsOn, bool doorIsClosed)
{
    _printStateBlockMsg(0, String(temperature) + " градусов");
    _printStateBlockMsg(1, _booleanValueMsg(compressorIsOn, "Компрессор", "вкл", "выкл"));
    _printStateBlockMsg(2, _booleanValueMsg(doorIsClosed, "Дверь", "закрыта", "открыта"));
}

void Notificator::askCloseTheDoor(Notificator::Severity sev)
{
    _doorOpenSeverity = sev;
    
    switch (_doorOpenSeverity) {
        case Notificator::Severity::POLITE:
            _dfplayer.playWithoutRepeats(DFPlayer::Message::CLOSE_THE_DOOR_POLITE);
            break;
        case Notificator::Severity::NERVOUS:
            _dfplayer.playWithoutRepeats(DFPlayer::Message::CLOSE_THE_DOOR_NERVOUS);
            break;
        case Notificator::Severity::ANGRY:
            _dfplayer.playWithoutRepeats(DFPlayer::Message::CLOSE_THE_DOOR_ANGRY);
            break;
        case Notificator::Severity::HEM:
            _dfplayer.playWithoutRepeats(DFPlayer::Message::HEM_ON);
            break;
        default:
            return;
    }

    _shouldNotifyWhenDoorIsClosed = true;
}

bool Notificator::shouldNotifyWhenDoorIsClosed() const
{
    return _shouldNotifyWhenDoorIsClosed;
}

void Notificator::notifyDoorIsClosed()
{
    switch (_doorOpenSeverity) {
        case Notificator::Severity::POLITE:
            _dfplayer.playWithoutRepeats(DFPlayer::Message::THANK_YOU);
            break;
        case Notificator::Severity::NERVOUS:
            _dfplayer.playWithoutRepeats(DFPlayer::Message::THATS_BETTER);
            break;
        case Notificator::Severity::ANGRY:
            _dfplayer.playWithoutRepeats(DFPlayer::Message::CLOSE_THE_DOOR_ANGRY);
            break;
        case Notificator::Severity::HEM:
            _dfplayer.playWithoutRepeats(DFPlayer::Message::HEM_OFF);
            break;
        default:
            return;
    }
    
    _doorOpenSeverity = Notificator::Severity::NONE;
    _shouldNotifyWhenDoorIsClosed = false;
}

String Notificator::_booleanValueMsg(bool value, String name, String trueState, String falseState)
{
    uint8_t baseLength = name.length() + 1; // one extra for space
    uint8_t maxStateLength = max(trueState.length(), falseState.length());
    
    String result = "";
    result.reserve(baseLength + maxStateLength); 
    
    result += name;
    result += " ";
 
    uint8_t stateLength = 0;
    if (value) {
      result += trueState;
      stateLength = trueState.length();
    }
    else {
      result += falseState;
      stateLength = falseState.length();
    }
    
    // to avoid text overlap all messages must have the same length
    for (int i = baseLength + stateLength; i < baseLength + maxStateLength; i++) {
        result += " ";
    }
    
    return result;
}

void Notificator::_printStateBlockMsg(uint8_t lineNumber, String msg)
{
    uint8_t leftTopY = UPPER_STATE_BLOCK_BORDER + lineNumber * _screen.getMinimumTextInterval(); // TODO: check for overflows!
    _screen.printText(LEFT_STATE_BLOCK_BORDER, leftTopY, msg);
}
