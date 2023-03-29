#include "screen.h"


class Notificator {
public:
  Notificator();
  void begin();
  
  void onSystemLoading();
  void onLoadingEnded();
  void onSystemLoaded();

private:
  Screen _screen;
};


