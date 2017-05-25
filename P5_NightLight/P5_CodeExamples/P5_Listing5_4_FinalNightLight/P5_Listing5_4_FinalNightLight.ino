/********************************************************************************
   Arduino Inventor's Guide - Project 5 (Listing 5-4)
   Night Light - Final Night Light Code

   Uses analogWrite() to create a custom colored night light

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
    analogWrite(11, 66);  //red
    analogWrite(10, 166); //green
    analogWrite(9, 199);  //blue
  }
  else
  {
    analogWrite(11, 0);  //red off
    analogWrite(10, 0);  //green off
    analogWrite(9, 0);   //blue off
  }
}

