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
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2); // set the LCD address to 0x27 for a 16x2 display

void setup() 
{
    lcd.begin();        // LCD initialize
    lcd.backlight();    // Backlight on

    lcd.print("ABCDEFGHIJKLMNOP");  // ABCDEFGHIJKLMNOP Print
    lcd.setCursor(0, 1);            // LCD x=0, y=1 point cursor
    lcd.print("QRSTUVWXYZ012345");  // QRSTUVWXYZ012345 Print
    lcd.noDisplay();                // LCD Off
    delay(500);
    lcd.display();                  // LCD On
    delay(500);
}

void loop() 
{
}
