#include "notificator.h"

#define UPPER_STATE_BLOCK_BORDER 65
#define LEFT_STATE_BLOCK_BORDER 70
#define STATE_BLOCK_LINES_AMOUNT 4


Notificator::Notificator()
    : _screen()
    , _dfplayer()
    , _doorOpenSeverity(Notificator::Severity::NONE)
    , _shouldNotifyWhenDoorIsClosed(false)
    , _isHEMMode(false)
{}

void Notificator::begin()
{
    _screen.begin();
    _dfplayer.begin();
}

void Notificator::onSystemLoading()
{
    _dfplayer.playWithoutRepeats(DFPlayer::Message::SYSTEM_LOADING);
    _screen.printTransparentText(55, 5, "Загрузка системы...", ILI9341_WHITE);
    _screen.printTransparentText(53, 110, "ANGRY FRIDGE", ILI9341_RED, Screen::TextSize::LARGE);
    _screen.printTransparentText(4, 220, "Powered by DCP Electronics", ILI9341_GREEN);
    delay(1000);
}

void Notificator::onLoadingEnded()
{
    _dfplayer.playWithoutRepeats(DFPlayer::Message::SYSTEM_LOADED);
    _screen.printTransparentText(55, 40, "СИСТЕМА ЗАГРУЖЕНА", ILI9341_GREEN);
    delay(1000);
    _screen.fillScreen(ILI9341_BLACK);
}

void Notificator::showStateBlock(
    float temperature,
    bool compressorIsOn,
    unsigned long untillCompressorTurnOn,
    bool doorIsClosed
)
{
    String messages[STATE_BLOCK_LINES_AMOUNT] = {
        String(temperature) + " градусов",
        _booleanValueMsg(compressorIsOn, "Компрессор", "вкл", "выкл"),
        _untillCompressorTurnOnMsg(untillCompressorTurnOn),
        _booleanValueMsg(doorIsClosed, "Дверь", "закрыта", "открыта")
    };
    
    for (int i = 0; i < STATE_BLOCK_LINES_AMOUNT; i++) {
        _printStateBlockMsg(i, messages[i]);
    }
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
            if (isHEMMode()) break;
            _dfplayer.playWithoutRepeats(DFPlayer::Message::HEM_ON, DFPlayer::Volume::LOUD);
            _switchHEMMode(true);
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
            _switchHEMMode(false);
            break;
        default:
            return;
    }
    
    _doorOpenSeverity = Notificator::Severity::NONE;
    _shouldNotifyWhenDoorIsClosed = false;
}

bool Notificator::isHEMMode() const
{
    return _isHEMMode;
}

void Notificator::notifyHEMMode()
{
    _screen.printTransparentText(30, 70, "РУЧ", ILI9341_RED, Screen::TextSize::HUGE);
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

String Notificator::_untillCompressorTurnOnMsg(unsigned long untillCompressorTurnOn)
{
    return "";
}

void Notificator::_printStateBlockMsg(uint8_t lineNumber, String msg)
{
    uint8_t interval = _screen.getMinimumTextInterval() + 10;
    uint8_t leftTopY = UPPER_STATE_BLOCK_BORDER + lineNumber * interval; // TODO: check for overflows!
    _screen.printText(LEFT_STATE_BLOCK_BORDER, leftTopY, msg);
}

void Notificator::_switchHEMMode(bool isOn)
{
    _screen.fillScreen(ILI9341_BLACK);
    _isHEMMode = isOn;
}
