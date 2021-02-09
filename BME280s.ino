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
#include <Wire.h>
#include <cactus_io_BME280_I2C.h>

BME280_I2C bme(0x76);                     // I2C using address 0x76

void setup()
{
  Serial.begin(115200);
  bme.begin();
  bme.setTempCal(-1.0);
}

void loop()
{
  bme.readSensor();

  Serial.print(F("Temperature: ")); Serial.print(bme.getTemperature_C());
  Serial.print("\t");
  Serial.print(F("Humidity: ")); Serial.println(bme.getHumidity());
  delay(3000);
}
