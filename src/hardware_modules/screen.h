#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"


class Screen {
public:
    Screen();
    void begin();
  
    enum TextSize {
        NORMAL = 2,
        LARGE  = 3,
    };
    void printText(
        uint8_t leftTopX,
        uint8_t leftTopY,
        const String& text,
        uint16_t color = ILI9341_WHITE,
        TextSize textSize = TextSize::NORMAL
    );
    void printTransparentText(
        uint8_t leftTopX,
        uint8_t leftTopY,
        const String& text,
        uint16_t color = ILI9341_WHITE,
        TextSize textSize = TextSize::NORMAL
    );

    uint8_t getMinimumTextInterval(TextSize textSize = TextSize::NORMAL) const;
    void fillScreen(uint16_t color);

private:
    void _internalPrint(
        uint8_t leftTopX,
        uint8_t leftTopY,
        const String& text,
        uint16_t color,
        TextSize textSize,
        bool transparent
    );
    
    String _utf8ToTFTEncoding(const String& source);
    bool _isRussianLetterBeginning(unsigned char currentByte);
    unsigned char _convertRussianLetter(unsigned char firstByte, unsigned char secondByte);
  
    Adafruit_ILI9341 _tft;
    TextSize _textSize;
};
