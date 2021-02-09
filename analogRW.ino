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
#define analogWritePin  17    // RX_LED

void setup()
{
  Serial.begin(115200);    
}

void loop()
{
  unsigned int sensorValue = analogRead(A0);                  // read the analog in value
  unsigned int pwmValue = map(sensorValue, 0, 1023, 0, 255);  // analogRead(0~1023), analogWrite(0~255)
  analogWrite(analogWritePin, pwmValue);                      // change the analog out value:

  Serial.print("sensor = [");
  Serial.print(sensorValue);
  Serial.print("]\t PWM = [");
  Serial.print(pwmValue);
  Serial.println("]");

  delay(1000);
}
