/********************************************************************************
   Arduino Inventor's Guide - Project 5 (Listing 5-1)
   Night Light - Simple RGB

   Change the HIGHs and LOWs to see what other colors you can create.

   Written by: Derek Runberg & Brian Huang, April 2016
   SparkFun Electronics & No Starch Press
 *******************************************************************************/

void setup()
{
  pinMode(11, OUTPUT);    //red
  pinMode(10, OUTPUT);    //green
  pinMode(9, OUTPUT);     //blue
}

void loop()
{
  digitalWrite(11, LOW);  //red
  digitalWrite(10, HIGH); //green
  digitalWrite(9, HIGH);  //blue
}

