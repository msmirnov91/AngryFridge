#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"


class Screen {
public:
    Screen();
    void begin();
  
    void printText(uint8_t leftTopX, uint8_t leftTopY, const String& text, uint16_t color = ILI9341_WHITE, bool transparent = false);
    uint8_t getMinimumTextInterval() const;
    void fillScreen(uint16_t color);

private:
    String _utf8ToTFTEncoding(const String& source);
    bool _isRussianLetterBeginning(unsigned char currentByte);
    unsigned char _convertRussianLetter(unsigned char firstByte, unsigned char secondByte);
  
    Adafruit_ILI9341 _tft;
};
