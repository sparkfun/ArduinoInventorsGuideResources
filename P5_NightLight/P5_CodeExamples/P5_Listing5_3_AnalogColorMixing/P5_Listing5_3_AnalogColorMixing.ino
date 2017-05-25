/********************************************************************************
   Arduino Inventor's Guide - Project 5 (Listing 5-3)
   Night Light - Simple Analog Color Mixing / Multicolored blink

   Demonstrates various colors and shades you can create with the RGB LED

   Written by: Derek Runberg & Brian Huang, April 2016
   SparkFun Electronics & No Starch Press
 *******************************************************************************/

void setup()
{
  pinMode(11, OUTPUT);    //red
  pinMode(10, OUTPUT);    //green
  pinMode(9, OUTPUT);     //blue
  calibrationValue = analogRead(A0);
}

void loop()
{
  analogWrite(11, 153);  //dark orchid purple
  analogWrite(10, 50);  
  analogWrite(9, 204);  
  delay(1000);
  
  analogWrite(11, 155);  //pale cerulean
  analogWrite(10, 196);  
  analogWrite(9, 226);  
  delay(1000);

  analogWrite(11, 255);  //cadmium yellow
  analogWrite(10, 246);  
  analogWrite(9, 0);  
  delay(1000);
}

