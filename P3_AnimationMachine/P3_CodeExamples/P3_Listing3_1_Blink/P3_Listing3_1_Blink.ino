/********************************************************************************
   Arduino Inventor's Guide - Project 3 (custom blink() function)
   Nine-Pixel Animation Machine

   Written by: Derek Runberg & Brian Huang, January 2016
   SparkFun Electronics & No Starch Press
 *******************************************************************************/

void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);

  //comment out the four lines above and un-comment this next line
  //of code to use the custom blink() function.
  //blink(13, 1000);
}

void blink(int pinNumber, int delayTime)
{
  digitalWrite(13, HIGH);
  delay(delayTime);
  digitalWrite(13, LOW);
  delay(delayTime);
}

