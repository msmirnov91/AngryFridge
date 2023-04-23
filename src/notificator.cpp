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
    _screen.printText(85, 110, "ANGRY FRIDGE", ILI9341_RED, true);
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
    const uint8_t interval = _screen.getMinimumTextInterval();
    
    uint8_t leftTopY = UPPER_STATE_BLOCK_BORDER;
    _screen.printText(LEFT_STATE_BLOCK_BORDER, leftTopY, String(temperature) + " градусов");
     
    String compressorMessage = _booleanStateMsg(compressorIsOn, "Компрессор", "вкл", "выкл");
    leftTopY += interval;
    _screen.printText(LEFT_STATE_BLOCK_BORDER, leftTopY, compressorMessage);
    
    String doorMessage = _booleanStateMsg(doorIsClosed, "Дверь", "закрыта", "открыта");
    leftTopY += interval;
    _screen.printText(LEFT_STATE_BLOCK_BORDER, leftTopY, doorMessage);
}

void Notificator::askCloseTheDoor(Notificator::Severity sev)
{
    _doorOpenSeverity = sev;
    
    switch (_doorOpenSeverity) {
        case Notificator::Severity::POLITE:
            break;
        case Notificator::Severity::NERVOUS:
            break;
        case Notificator::Severity::ANGRY:
            break;
        case Notificator::Severity::HEM:
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
            break;
        case Notificator::Severity::NERVOUS:
            break;
        case Notificator::Severity::ANGRY:
            break;
        case Notificator::Severity::HEM:
            break;
        default:
            return;
    }
    
    _doorOpenSeverity = Notificator::Severity::NONE;
    _shouldNotifyWhenDoorIsClosed = false;
}

String Notificator::_booleanStateMsg(bool value, String name, String trueState, String falseState)
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
