#include "screen.h"
#include "pin_defines.h"

#define ALBUM_ORIENTATION 1

#define RUSSIAN_LETTER_BEGINNING_BYTE_1 0xD0
#define RUSSIAN_LETTER_BEGINNING_BYTE_2 0xD1
#define FIRST_RUSSIAN_LETTERS_RANGE_OFFSET 0x2F
#define SECOND_RUSSIAN_LETTERS_RANGE_OFFSET 0x6F

#define YO_UPPER_TWO_BYTES 0x81
#define YO_UPPER_ONE_BYTE 0xA8
#define YO_LOWER_TWO_BYTES 0x91
#define YO_LOWER_ONE_BYTE 0xB7


Screen::Screen()
    : _tft(Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_SDA, TFT_CLK, TFT_RST, TFT_MISO))
{}

void Screen::begin()
{
    _tft.begin();
    _tft.setRotation(ALBUM_ORIENTATION);
    _tft.setTextSize(2);
}

void Screen::printText(uint8_t leftTopX, uint8_t leftTopY, const String& text, uint16_t color, bool transparent)
{
	if (transparent) {
		_tft.setTextColor(color);
	}
	else {
		_tft.setTextColor(color, ILI9341_BLACK);
	}
    _tft.setCursor(leftTopX, leftTopY);
    _tft.print(_utf8ToTFTEncoding(text));
}

void Screen::drawCircle(uint8_t x, uint8_t y, uint8_t radius, uint16_t color)
{
    _tft.fillCircle(x, y, radius, color);
}

void Screen::fillScreen(uint16_t color)
{
    _tft.fillScreen(color);
}

String Screen::_utf8ToTFTEncoding(const String& source)
{
	/*
	    It looks like TFT display library accepts russian letters
	    in very similar to windows 1251 one-byte encoding. Symbols in it
	    are shifted by 1 relatively to windows 1251, so that offset
		between utf-8 byte and this encoding byte is less by 1 too
        (0x2F instead of 0x30 and 0x6F instead of 0x70).
		For more information see:
		
		https://arduino.ru/forum/programmirovanie/rusifikatsiya-biblioteki-adafruit-gfx-i-vyvod-russkikh-bukv-na-displei-v-kodi
		https://wiki.iarduino.ru/page/encoding-arduino/
	*/
	char* tmp = new char[source.length() + 1];
	for (int i = 0; i < source.length() + 1; i++) {
		tmp[i] = 0;
	}

    for (int i = 0, k = 0; i < source.length(); i++, k++) {	
		char n = source[i];
		if (_isRussianLetterBeginning(n)) {
			n = _convertRussianLetter(n, source[++i]);
		}
		tmp[k] = n;
    }
	
	String target(tmp); // try to avoid multiple allocations
	delete[] tmp;
    return target;
}

bool Screen::_isRussianLetterBeginning(unsigned char currentByte)
{
	return currentByte == RUSSIAN_LETTER_BEGINNING_BYTE_1
		   || currentByte == RUSSIAN_LETTER_BEGINNING_BYTE_2;
}

unsigned char Screen::_convertRussianLetter(unsigned char firstByte, unsigned char secondByte)
{
	switch (firstByte) {
	    case RUSSIAN_LETTER_BEGINNING_BYTE_1: {
		    if (secondByte == YO_UPPER_TWO_BYTES) {
				return YO_UPPER_ONE_BYTE;
			}
		    if (secondByte >= 0x90 && secondByte <= 0xBF) {
				return secondByte + FIRST_RUSSIAN_LETTERS_RANGE_OFFSET;
		    }
	    }
	    case RUSSIAN_LETTER_BEGINNING_BYTE_2: {
			if (secondByte == YO_LOWER_TWO_BYTES) {
				return YO_LOWER_ONE_BYTE;
			}
		    if (secondByte >= 0x80 && secondByte <= 0x8F) {
				return secondByte + SECOND_RUSSIAN_LETTERS_RANGE_OFFSET;
		    }
	    }
	}
	return secondByte;
}
