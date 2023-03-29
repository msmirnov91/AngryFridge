#include "notificator.h"


Notificator::Notificator()
  : _screen()
{}

void Notificator::begin()
{
  _screen.begin();
}

void Notificator::onSystemLoading()
{
  _screen.printRussianText(55, 5, "Загрузка системы...", ILI9341_WHITE);
  _screen.drawCircle(160, 120, 15, ILI9341_YELLOW);
  _screen.printText(4, 220, "Powered by DCP Electronics", ILI9341_GREEN);
}

void Notificator::onLoadingEnded()
{
  _screen.fillScreen(ILI9341_BLACK);
}

void Notificator::onSystemLoaded()
{
  _screen.printRussianText(55, 100, "Система загружена", ILI9341_GREEN);
}

void Notificator::showTemperature(int temperature)
{
  _screen.printRussianText(40, 120, String(temperature) + " градусов", ILI9341_WHITE);
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
  _screen.printRussianText(40, 140, msg, ILI9341_WHITE);
}
 
