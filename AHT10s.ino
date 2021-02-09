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
#include <AHT10.h>
#include <Wire.h>

AHT10 myAHT10(AHT10_ADDRESS_0X38);

void setup()
{
  Serial.begin(115200);
  myAHT10.begin();
}

void loop()
{
  Serial.print(F("Temperature: ")); Serial.print(myAHT10.readTemperature());
  Serial.print("\t");
  Serial.print(F("Humidity: ")); Serial.println(myAHT10.readHumidity());
  delay(3000);
}
