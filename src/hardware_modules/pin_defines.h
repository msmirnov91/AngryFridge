#if (ARDUINO >= 100)
    #include <Arduino.h>
#else
    #include <WProgram.h>
    #include <pins_arduino.h>
#endif

#define TFT_DC 9
#define TFT_CS 10
#define TFT_RST 8

// Uno Hardware SPI
#define TFT_MISO 12  // NOT CONNECTED
#define TFT_SDA 11   // MOSI
#define TFT_CLK 13

#define SOFTWARE_SERIAL_RX 2
#define SOFTWARE_SERIAL_TX 3

#define THERMOMETER_PIN 4
#define COMPRESSOR_PIN 5
#define DOOR_PIN 6
#define LAMP_PIN 7
