/********************************************************************************
   Arduino Inventor's Guide - Project 8 (Bonus)
   Drawbot Bonus "Logo Turtle"

   Bonus Turtle Program -- Upload this sketch and then open up the
   Serial monitor. Type in some "logo" commands such as fd 10 or bk 20 to drive 
   the drawbot turtle forward 10 steps or backward 20 steps.

   You may need to tune some of the parameters to get the turning to get a nice
   90 degree turn, but there is also a rt and lt command for turning.

   Written by: Derek Runberg & Brian Huang, February 2017
   SparkFun Electronics & No Starch Press
 *******************************************************************************/
const byte AIN1 = 13;
const byte AIN2 = 12;
const byte PWMA = 11;

const byte BIN1 = 8;
const byte BIN2 = 9;
const byte PWMB = 10;

const int turnFactor = 8;       // tune or change this to adjust the turning calibration
const int straightFactor = 20;  // tune or change this to adjust the fd / bk calibration

int delayTime;
int baseSpeed = 150;

String command;
String parameter;

void setup()
{
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  Serial.begin(9600);
  Serial.println("Enter a command and a parameter. Known commands include (fd, bk, rt, and lt) followed by a number.");

}

void loop()
{
  if (Serial.available() > 0)
  {
    command = Serial.readStringUntil(' ');
    parameter = Serial.readStringUntil(' ');


    Serial.print(command);
    Serial.print(" ");
    Serial.println(parameter.toInt());
    if (command == "fd")
    {
      Serial.println("F");
      setMotorA(baseSpeed);
      setMotorB(-baseSpeed);
      delay(straightFactor * parameter.toInt());
      setMotorA(0);
      setMotorB(0);
    }
    else if (command == "bk")
    {
      Serial.println("B");
      setMotorA(-baseSpeed);
      setMotorB(baseSpeed);
      delay(straightFactor * parameter.toInt());
      setMotorA(0);
      setMotorB(0);
    }
    else if (command == "rt")
    {
      Serial.println("R");
      setMotorA(baseSpeed);
      setMotorB(baseSpeed);
      delay(turnFactor * parameter.toInt());
      setMotorA(0);
      setMotorB(0);
    }
    else if (command == "lt")
    {
      Serial.println("L");
      setMotorA(-baseSpeed);
      setMotorB(-baseSpeed);
      delay(turnFactor * parameter.toInt());
      setMotorA(0);
      setMotorB(0);
    }
  }
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

