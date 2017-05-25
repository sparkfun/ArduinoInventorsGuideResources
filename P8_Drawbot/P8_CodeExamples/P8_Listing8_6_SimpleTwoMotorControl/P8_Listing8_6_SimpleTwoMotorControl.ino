/********************************************************************************
   Arduino Inventor's Guide - Project 8 (Listing 8-6)
   Drawbot

   Extend what we did in Listing 8-3 to add a custom functions for both Motor A 
   and Motor B

   Written by: Derek Runberg & Brian Huang, January 2017
   SparkFun Electronics & No Starch Press
 *******************************************************************************/
const byte AIN1 = 13;
const byte AIN2 = 12;
const byte PWMA = 11;

const byte BIN1 = 8;
const byte BIN2 = 9;
const byte PWMB = 10;

void setup()
{
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
}

void loop()
{
  //drive forward medium speed for one second
  setMotorA(100);  
  setMotorB(-100);
  delay(1000);

  //drive backward quickly for one second
  setMotorA(-255);  
  setMotorB(255);  
  delay(1000);

  //stop
  setMotorA(0);
  setMotorB(0);
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

/********************************************************************************/
//custom function to set the motor speed of Motor B
/********************************************************************************/
void setMotorB(int motorSpeed)
{
  if (motorSpeed > 0)
  {
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);
  }
  else if (motorSpeed < 0)
  {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);
  }
  else
  {
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, HIGH);
  }
  analogWrite(PWMB, abs(motorSpeed));
}

