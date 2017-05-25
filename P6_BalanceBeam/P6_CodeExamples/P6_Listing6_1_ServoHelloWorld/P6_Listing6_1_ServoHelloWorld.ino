/********************************************************************************
   Arduino Inventor's Guide - Project 6 (Listing 6-1)
   Balance Beam - servo "Hello world"

   Initates the Servo object and then moves it to 90 degree position. 
   Pre-set the servo by gently turning it all the way either clockwise or counter clockwise
   before plugging it into the circuit. When the program starts up, the servo horn should move
   to the 90 degree position.

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
  myServo.write(90);
}
