/*
    [ATmega32U4 Pinout]
              ----------
        TX=1-| ProMicro |-RAW
        RX=0-|          |-GND
         GND-|          |-RST
         GND-|          |-VCC
       SDA=2-|          |-21=A3
    SCL=3(~)-|          |-20=A2
        A6=4-|          |-19=A1
        5(~)-|          |-18=A0
     A7=6(~)-|          |-15=SCLK
           7-|          |-14=MISO
        A8=8-|          |-16=MOSI
     A9=9(~)-|          |-10(~)=A10
              ----------
  https://github.com/MCUdude/MicroCore/tree/master/avr/libraries/EEPROM
  AVR processors EEPROM sizes :
  - Attiny13    : 64b EEPROM storage.
  - Attiny25~85 : 128~512b EEPROM storage.
  - Atmega 328P : 1kb EEPROM storage.
  - Atmega 32U4 : 1kb EEPROM storage.
  - Atmega 2560 : 4kb EEPROM storage.
*/
#include <EEPROM.h>

unsigned int address = 0;
byte value;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  for (address = 0; address < EEPROM.length(); address++)
  {
    unsigned int val = random(EEPROM.length());
    EEPROM.write(address, val);
  }

  for (address = 0; address < EEPROM.length(); address++)
  {
    value = EEPROM.read(address);

    Serial.print(address);
    Serial.print("\t");
    Serial.print(value, DEC);
    Serial.println();
  }
}
