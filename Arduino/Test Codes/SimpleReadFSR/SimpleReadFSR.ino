//https://learn.adafruit.com/force-sensitive-resistor-fsr/using-an-fsr

int FSRpin = 0; // pin for force sensitive resistor is 0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(FSRpin));

}
