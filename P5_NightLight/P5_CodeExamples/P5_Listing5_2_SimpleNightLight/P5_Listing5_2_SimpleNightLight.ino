/********************************************************************************
   Arduino Inventor's Guide - Project 5 (Listing 5-2)
   Night Light

   Turns on the RGB LED when the light drops 50 below the calibration value
   measured at start-up.

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
  if (lightValue < calibrationValue - 50)
  {
    digitalWrite(11, LOW);  //red
    digitalWrite(10, HIGH); //green
    digitalWrite(9, HIGH);  //blue
  }
  else
  {
    digitalWrite(11, LOW);  //red
    digitalWrite(10, LOW); //green
    digitalWrite(9, LOW);  //blue
  }
}

