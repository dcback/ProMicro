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
*/
#include <OneWire.h>
#include <DallasTemperature.h>
#include <TM1637Display.h>

#define CLK   5
#define DIO   6
#define ONE_WIRE_BUS 4

TM1637Display display(CLK, DIO);

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup()
{
  Serial.begin(115200);
  display.setBrightness(0x07);
  sensors.begin();
}

void loop()
{
  sensors.requestTemperatures();
  float temp = sensors.getTempCByIndex(0);
  Serial.print(F("Temperature: ")); Serial.println(temp);
  display.showNumberDecEx(temp * 100, 0b01000000, false);
  delay(1000);
}
