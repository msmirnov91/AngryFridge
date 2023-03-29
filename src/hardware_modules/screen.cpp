#include "screen.h"

#define TFT_DC 9
#define TFT_CS 10
#define TFT_RST 8

// Uno Hardware SPI
#define TFT_MISO 12  // NOT CONNECTED
#define TFT_SDA 11   // MOSI
#define TFT_CLK 13


Screen::Screen()
  : _tft(Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_SDA, TFT_CLK, TFT_RST, TFT_MISO))
{}

void Screen::begin()
{
  _tft.begin();
  _tft.setRotation(1);  // Album orientation
  _tft.setTextSize(2);
}

void Screen::printText(uint8_t left, uint8_t top, const String& text, uint16_t color)
{
  _tft.setTextColor(color);
  _tft.setCursor(left, top);
  _tft.print(text);
}

void Screen::printRussianText(uint8_t left, uint8_t top, const String& text, uint16_t color)
{
  printText(left, top, _utf8rus(text), color);
}

void Screen::drawCircle(uint8_t x, uint8_t y, uint8_t radius, uint16_t color)
{
  _tft.fillCircle(x, y, radius, color);
}

void Screen::fillScreen(uint16_t color)
{
  _tft.fillScreen(color);
}

String Screen::_utf8rus(const String& source)  // Функция для конвертации русских символов из двубайтовой кодировки в однобайтовую
{
  int i,k;
  String target;
  unsigned char n;
  char m[2] = { '0', '\0' };
  k = source.length(); i = 0;
  while (i < k) {
    n = source[i]; i++;

    if (n >= 0xBF){
      switch (n) {
        case 0xD0: {
          n = source[i]; i++;
          if (n == 0x81) { n = 0xA8; break; }
          if (n >= 0x90 && n <= 0xBF) n = n + 0x2F;
          break;
        }
        case 0xD1: {
          n = source[i]; i++;
          if (n == 0x91) { n = 0xB7; break; }
          if (n >= 0x80 && n <= 0x8F) n = n + 0x6F;
          break;
        }
      } 
    }
    m[0] = n; target = target + String(m);
  }
  return target;
}

