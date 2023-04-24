# AngryFridge

An Arduino project that turns an ordinary refrigerator into an angry curmudgeon.

## Supported platforms
Currently supports only `Arduion Uno`. `Mega` and `Nano` will be supported later. To choose the platform one should define an appropriate macro constant.

## Used libraries
- `Adafruit_GFX` [github](https://github.com/adafruit/Adafruit-GFX-Library)
- `Adafruit_ILI9341` [github](https://github.com/adafruit/Adafruit_ILI9341)
- `DFPlayer Mini mp3 Arduino Library` [download](https://iarduino.ru/file/140.html) NB: tracks get their numbers from the order in which they were copied to SD card, so to keep the strict order one should copy files one by one. For more info click [here](https://compacttool.ru/miniatyurniy-stereo-audio-mp3-pleer-dfplayer-mini-dfrobot).
- `microDS18B20` [github](https://github.com/GyverLibs/microDS18B20)

## Used hardware
- 240X320 LCD SPI TFT display controlled by `ILI9341` [example](https://www.youtube.com/watch?v=pfP4Pv3y85Y) (`Adafruit_GFX` and `Adafruit_ILI9341` are available here as .zip archives)
- `DFPlayer mini` MP3 module [example](https://lesson.iarduino.ru/page/urok-17-podklyuchenie-mini-mp3-pleera-k-arduino/)
- `DS18B20` temperature sensor [example](https://kit.alexgyver.ru/tutorials/ds18b20/)

## Electric circuit
not developed yet

## How to handle inductive load (compressor) switching
The compressor switching may lead to high-voltage transients that can disrupt normal operation or even damage the involved equipment. This can be handled by proper `RC` - circuits. [Here](https://www.mzta.ru/images/304/iskrogasyashchiyetsepi.pdf) is a good paper describing what exactly is going on and how to calculate appropriate values of `R` and `C`. For my fridge I choosed the `47 pf` capacitor and `40 ohm` `2w` resistor.

## Sounds
Click [here](https://voxworker.com/ru) to generate mp3 by text
