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
  // 10-bit ADC(0~1023)
  unsigned int A0_value = analogRead(A0);
  unsigned int A1_value = analogRead(A1);
  unsigned int A2_value = analogRead(A2);
  unsigned int A3_value = analogRead(A3);

  Serial.print("A0_Value["); Serial.print(A0_value); Serial.print("] ");
  Serial.print("A1_Value["); Serial.print(A1_value); Serial.print("] ");
  Serial.print("A2_Value["); Serial.print(A2_value); Serial.print("] ");
  Serial.print("A3_Value["); Serial.print(A3_value); Serial.println("]");

  delay(1000);
}
