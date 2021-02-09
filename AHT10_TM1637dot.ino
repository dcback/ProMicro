/*  https://github.com/avishorp/TM1637
    https://robojax.com/learn/arduino/robojax-TM1637_display_manual.pdf
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
*/
#include <AHT10.h>
#include <Wire.h>
#include <TM1637Display.h>

// FND Module connection pins (Digital Pins)
#define CLK 4
#define DIO 5

// The amount of time (in milliseconds) between tests
#define DELAY   3000

TM1637Display display(CLK, DIO);
AHT10 myAHT10(AHT10_ADDRESS_0X38);

void setup()
{
  display.clear();
  myAHT10.begin() ;
}

void loop()
{
  display.setBrightness(7);   // 0~7, 7(maxBright)
  float Temp = myAHT10.readTemperature() * 100.0;
  display.showNumberDecEx(Temp, 0b01000000, false, 4, 0);
  delay(DELAY);

  display.setBrightness(1);   // 0~7, 7(maxBright)
  float Humi = myAHT10.readHumidity() * 100.0;
  display.showNumberDecEx(Humi, 0b01000000, false, 4, 0);
  delay(DELAY);
}
