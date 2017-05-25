/********************************************************************************   
   Arduino Inventor's Guide - Project 8 (Hack Section)
   Drawbot Serial Control
  
   Upload this sketch and then open up the Serial monitor.   
  
   Type in three values with a space in between them to set the left motor
   speed, right motor speed, and duration for the turtle. And then hit ENTER or
   click [send]. You can now control the turtle without having to re-upload your
   code!
   
   Written by: Derek Runberg & Brian Huang, February 2017
   SparkFun Electronics & No Starch Press
 *******************************************************************************/
const byte AIN1 = 13;
const byte AIN2 = 12;
const byte PWMA = 11;

const byte BIN1 = 8;
const byte BIN2 = 9;
const byte PWMB = 10;

int speedA;
int speedB;
int delayTime;

void setup()
{
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);

  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)
  {
    speedA = Serial.parseInt();
    speedB = Serial.parseInt();
    delayTime = Serial.parseInt();

    setMotorA(speedA);
    setMotorB(speedB);
    delay(delayTime);

    setMotorA(0);
    setMotorB(0);
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

