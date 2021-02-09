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
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 4
#define DIO 5

#define readV0  A0
#define readV1  A1
#define readV2  A2
#define readV3  A3

// The amount of time (in milliseconds) between tests
#define DELAY   3000

TM1637Display display(CLK, DIO);

unsigned int V0 = 0;
unsigned int V1 = 0;
unsigned int V2 = 0;
unsigned int V3 = 0;

void setup()
{
  Serial.begin(115200);
  display.setBrightness(7); // 0~7, 7(maxBright)
  display.clear();

  pinMode(readV0, INPUT);
  pinMode(readV1, INPUT);
  pinMode(readV2, INPUT);
  pinMode(readV3, INPUT);
}

void loop()
{
  V0 = analogRead(readV0);
  display.showNumberDec(V0, false);
  Serial.print("V0 :");
  Serial.println(V0);
  delay(DELAY);

  V1 = analogRead(readV1);
  display.showNumberDec(V1, false);
  Serial.print("V1 :");
  Serial.println(V1);
  delay(DELAY);

  V2 = analogRead(readV2);
  display.showNumberDec(V2, false);
  Serial.print("V2 :");
  Serial.println(V2);
  delay(DELAY);

  V3 = analogRead(readV3);
  display.showNumberDec(V3, false);
  Serial.print("V3 :");
  Serial.println(V3);
  delay(DELAY);
}
