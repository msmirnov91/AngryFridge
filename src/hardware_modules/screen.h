#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"


class Screen {
public:
    Screen();
    void begin();
  
    void printText(uint8_t leftTopX, uint8_t top, const String& text, uint16_t color = ILI9341_WHITE, bool transparent = false);
    void printRussianText(uint8_t leftTopX, uint8_t top, const String& text, uint16_t color = ILI9341_WHITE, bool transparent = false);
  
    void drawCircle(uint8_t x, uint8_t y, uint8_t radius, uint16_t color);
    void fillScreen(uint16_t color);

private:
    String _utf8ToWin1251(const String& source);
  
    Adafruit_ILI9341 _tft;
};
