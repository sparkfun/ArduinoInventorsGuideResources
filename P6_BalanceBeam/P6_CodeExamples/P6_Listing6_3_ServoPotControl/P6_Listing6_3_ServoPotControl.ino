/********************************************************************************
   Arduino Inventor's Guide - Project 6 (Listing 6-3)
   Balance Beam - complete sketch

   This sketch uses a potentiometer on pin A0. This is similar to the servo 
   knob example. Turning the knob (potentiometer) moves the servo.

   Written by: Derek Runberg & Brian Huang, May 2016
   SparkFun Electronics & No Starch Press
 *******************************************************************************/
 
#include<Servo.h>
Servo myServo;
int potVal;
int anglePosition;

void setup()
{
  myServo.attach(9);
}

void loop()
{
  potVal = analogRead(A0);
  anglePosition = map(potVal, 0, 1023, 10, 170); 
  myServo.write(anglePosition);
  delay(20);
}
