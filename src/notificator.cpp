#include "notificator.h"


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

void Notificator::showTemperature(float temperature)
{
    _screen.printText(70, 80, String(temperature) + " градусов");
}

void Notificator::showCompressorState(bool isOn)
{
    String msg = "Компрессор ";
    if (isOn) {
      msg += "вкл";
    }
    else {
      msg += "выкл";
    }
    _screen.printText(70, 100, msg);
}

void Notificator::showDoorState(bool isClosed)
{
    String msg = "Дверь ";
    if (isClosed) {
      msg += "закрыта";
    }
    else {
      msg += "открыта";
    }
    _screen.printText(70, 120, msg);
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
