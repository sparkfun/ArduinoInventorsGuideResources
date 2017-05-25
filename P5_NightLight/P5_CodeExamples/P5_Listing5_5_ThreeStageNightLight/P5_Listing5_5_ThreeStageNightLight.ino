/********************************************************************************
   Arduino Inventor's Guide - Project 5 (Listing 5-5)
   Night Light (Three-stage Night-Light)

   Shows off three various colors based on the light level in the room.

   Written by: Derek Runberg & Brian Huang, April 2016
   SparkFun Electronics & No Starch Press
 *******************************************************************************/
int calibrationValue;
int lightValue;

void setup()
{
  pinMode(11, OUTPUT);    //red
  pinMode(10, OUTPUT);    //green
  pinMode(9, OUTPUT);     //blue
  calibrationValue = analogRead(A0);
}

void loop()
{
  lightValue = analogRead(A0);
  if (lightValue < calibrationValue - 200)
  {
    //do if it is completely dark
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
  }
  else if (lightValue < calibrationValue - 50)
  {
    //do if it is a little dim
    digitalWrite(11, LOW);
    digitalWrite(10, HIGH);
  }
  else
  {
    //do if it is bright
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
  }
}

