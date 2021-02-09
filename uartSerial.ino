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
  Serial.println("ProMicro Serial Print");
  delay(1000);
}
