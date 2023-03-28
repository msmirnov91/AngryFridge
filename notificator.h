#include "screen.h"

class Notificator {
public:
  Notificator()
    : _screen()
  {}

  void begin()
  {
    _screen.begin();
  }

  void onSystemLoading()
  {
    _screen.printRussianText(55, 5, "Загрузка системы...", ILI9341_WHITE);
    _screen.drawCircle(160, 120, 15, ILI9341_YELLOW);
    _screen.printText(4, 220, "Powered by DCP Electronics", ILI9341_GREEN);
  }

  void onLoadingEnded()
  {
    _screen.fillScreen(ILI9341_BLACK);
  }

  void onSystemLoaded()
  {
    _screen.printRussianText(55, 120, "Система загружена", ILI9341_GREEN);
  }
  
private:
  Screen _screen;
};

Notificator notificator;


