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
    _screen.drawCircle(160, 120, 15, ILI9341_YELLOW);
    _screen.printText(4, 220, "Powered by DCP Electronics", ILI9341_GREEN, true);
}

void Notificator::onLoadingEnded()
{
    _screen.fillScreen(ILI9341_BLACK);
}

void Notificator::onSystemLoaded()
{
    _dfplayer.playWithoutRepeats(DFPlayer::Message::SYSTEM_LOADED);
    _screen.printText(55, 80, "Система загружена", ILI9341_GREEN);
}

void Notificator::showTemperature(float temperature)
{
    _screen.printText(40, 120, String(temperature) + " градусов");
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
    _screen.printText(40, 140, msg);
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
