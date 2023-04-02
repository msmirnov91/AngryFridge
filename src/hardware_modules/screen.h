#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"


class Screen {
public:
    Screen();
    void begin();
  
    void printText(uint8_t left, uint8_t top, const String& text, uint16_t color = ILI9341_WHITE);
    void printRussianText(uint8_t left, uint8_t top, const String& text, uint16_t color = ILI9341_WHITE);
  
    void drawCircle(uint8_t x, uint8_t y, uint8_t radius, uint16_t color);
    void fillScreen(uint16_t color);

private:
    String _utf8rus(const String& source);  // Функция для конвертации русских символов из двубайтовой кодировки в однобайтовую
  
    Adafruit_ILI9341 _tft;
};
