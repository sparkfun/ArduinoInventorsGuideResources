/********************************************************************************
   Arduino Inventor's Guide - Project 8 (Listing 8-1)
   Drawbot

   Simple H-Bridge Motor Control Example. This demonstrate how we can spin the motor
   both clockwise and counter clock-wise, and stop (apply brakes to) the motor.

   Written by: Derek Runberg & Brian Huang, January 2017
   SparkFun Electronics & No Starch Press
 *******************************************************************************/
const byte AIN1 = 13;
const byte AIN2 = 12;
const byte PWMA = 11;

void setup()
{
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
}

void loop()
{
  //set direction to clockwise
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 50);  //set speed to slow...
  delay(1000);

  //set direction to counterclockwise
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, 255); //set speed to fast!
  delay(1000);

  //brake
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, HIGH);
  delay(1000);
}

/
