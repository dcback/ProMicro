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
  Serial.println("[ProMicro pinTest]");

  Serial.print("A0="); Serial.println(A0);
  Serial.print("A1="); Serial.println(A1);
  Serial.print("A2="); Serial.println(A2);
  Serial.print("A3="); Serial.println(A3);
  Serial.print("A6="); Serial.println(A6);
  Serial.print("A7="); Serial.println(A7);
  Serial.print("A8="); Serial.println(A8);
  Serial.print("A9="); Serial.println(A9);

  delay(1000);
}
