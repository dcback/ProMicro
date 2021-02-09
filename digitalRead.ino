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
void setup()
{
  Serial.begin(115200);
}

void loop()
{
  unsigned int D0 = digitalRead(0);
  unsigned int D1 = digitalRead(1);
  unsigned int D2 = digitalRead(2);
  unsigned int D3 = digitalRead(3);
  unsigned int D4 = digitalRead(4);
  unsigned int D5 = digitalRead(5);

  Serial.print("D0["); Serial.print(D0); Serial.print("] ");
  Serial.print("D1["); Serial.print(D1); Serial.print("] ");
  Serial.print("D2["); Serial.print(D2); Serial.print("] ");
  Serial.print("D3["); Serial.print(D3); Serial.print("] ");
  Serial.print("D4["); Serial.print(D4); Serial.print("] ");
  Serial.print("D5["); Serial.print(D5); Serial.println("]");
  delay(1000);
}
