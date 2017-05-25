/********************************************************************************
   Arduino Inventor's Guide - Project 8 (Listing 8-3)
   Drawbot

   Custom Function used to control Motor A. Simplifes the control of the motor to 
   a single function: setMotorA()

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
  setMotorA(100);  //go medium speed...
  delay(1000);

  //set direction to counterclockwise
  setMotorA(-255);  //go fast!
  delay(1000);

  //stop
  setMotorA(0);
  delay(1000);
}

/********************************************************************************/
//custom function to set the motor speed of Motor A
/********************************************************************************/
void setMotorA(int motorSpeed)
{
  if (motorSpeed > 0)
  {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
  }
  else if (motorSpeed < 0)
  {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
  }
  else
  {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, HIGH);
  }
  analogWrite(PWMA, abs(motorSpeed));
}


