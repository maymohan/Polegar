// REFERENCE: https://learn.adafruit.com/force-sensitive-resistor-fsr/using-an-fsr
#include <Servo.h>

int FSRpin = 0, fsrAvg = 0;
int servoPower = 10;
Servo myservo;  // create servo object to control a servo
int servoPos = 0, fsrValue = 0, counter = 0;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  fsrAvg = analogRead(FSRpin);
  pinMode(servoPower,OUTPUT);
  digitalWrite(servoPower, HIGH);
}

void loop()
{
  fsrValue = analogRead(FSRpin);
  fsrAvg = fsrValue;// + fsrAvg) / 2;
//  if (counter > 10)
//  {
    //servoPos = servoMapper(fsrAvg);
    servoPos = map(fsrAvg,0,1023,0,180);
    Serial.println(servoPos);
    if (servoPos > 30)
      myservo.write(servoPos);
    counter = -1;
 // }
  counter ++;
}
//
//int servoMapper(int fsrAvg)
//{
//  if (fsrAvg > 0 & fsrAvg < 114)
//    return 20;
//
//  if (fsrAvg > 115 & fsrAvg <= 228)
//    return 40;
//
//  if (fsrAvg > 229 & fsrAvg <= 341)
//    return 60;
//
//  if (fsrAvg > 342 & fsrAvg <= 455)
//    return 80;
//
//  if (fsrAvg > 456 & fsrAvg <= 568)
//    return 100;
//
//  if (fsrAvg > 569 & fsrAvg <= 683)
//    return 120;
//
//  if (fsrAvg > 684 & fsrAvg <= 796)
//    return 140;
//
//  if (fsrAvg > 797 & fsrAvg <= 910)
//    return 160;
//
//  if (fsrAvg > 911 & fsrAvg <= 1023)
//    return 179;
//}

