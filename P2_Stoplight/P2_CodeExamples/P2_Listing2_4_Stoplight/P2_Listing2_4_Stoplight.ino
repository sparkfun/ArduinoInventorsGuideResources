/********************************************************************************
   Arduino Inventor's Guide - Project 2
   Stop Light

   Written by: Derek Runberg & Brian Huang, Oct. 2015
   SparkFun Electronics & No Starch Press
 *******************************************************************************/

byte redPin = 13;
byte ylwPin = 12;
byte grnPin = 11;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(ylwPin, OUTPUT);
  pinMode(grnPin, OUTPUT);
}

void loop()
{
  //red on
  digitalWrite(redPin, HIGH);
  digitalWrite(ylwPin, LOW);
  digitalWrite(grnPin, LOW);
  delay(2000);

  //green on
  digitalWrite(redPin, LOW);
  digitalWrite(ylwPin, LOW);
  digitalWrite(grnPin, HIGH);
  delay(1500);

  //yellow on
  digitalWrite(redPin, LOW);
  digitalWrite(ylwPin, HIGH);
  digitalWrite(grnPin, LOW);
  delay(500);
}
