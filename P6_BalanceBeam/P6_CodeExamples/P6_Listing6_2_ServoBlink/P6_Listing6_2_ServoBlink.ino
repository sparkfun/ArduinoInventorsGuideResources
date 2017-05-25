/********************************************************************************
   Arduino Inventor's Guide- Project 6 (Listing 6-2)
   Balance Beam - servo blink

   Moves the servo back and forth - like a 'blink' or a sprinkler system

   Written by: Derek Runberg & Brian Huang, May 2016
   SparkFun Electronics & No Starch Press
 *******************************************************************************/
 
#include<Servo.h>
Servo myServo;
void setup()
{
  myServo.attach(9);
}

void loop()
{
  myServo.write(10);
  delay(1000);
  myServo.write(170);
  delay(1000);
}
