#include "tft.h"

void setup(){
  tft.begin();
  tft.setRotation(1);  // Album orientation

  tft.setTextSize(2);
 
  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(55,5);  // Top left text position
  tft.print(utf8rus("Загрузка системы..."));

  int x = 160;
  int y = 120;
  int radius = 15;
  tft.fillCircle(x, y, radius, ILI9341_YELLOW);
  
  tft.setTextColor(ILI9341_GREEN);
  tft.setCursor(4,220);
  tft.print("Powered by DCP Electronics");

  delay(5000);
  tft.fillScreen(ILI9341_BLACK);
}

void loop()
{
  tft.setCursor(55,120);
  tft.print(utf8rus("Система загружена"));
}

