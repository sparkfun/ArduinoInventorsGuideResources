/********************************************************************************
   Arduino Inventor's Guide - Project 9 (Bonus)
   Drag Race Timer - Two Cars

   Uses a button to trigger moving a servo arm up (starting gate) to start the
   race. This one uses two photoresistors to detect two race cars. The timer runs
   until one of the light sensors is crossed at the end. 

   The winner and the elapsed raceTime is shown on the LCD.

   Written by: Derek Runberg & Brian Huang, March 2017
   SparkFun Electronics & No Starch Press
 *******************************************************************************/
#include<LiquidCrystal.h>
#include<Servo.h>

LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
Servo startingGate;

const byte buttonPin = 5;
const byte servoPin = 4;
const byte finishSensor1Pin = A0;
const byte finishSensor2Pin = A1;

const int darkThreshold = 500;

int finishSensor1;
int finishSensor2;
boolean finishFlag = false;
long startTime;
long stopTime;
float raceTime;

void setup()
{
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);

  startingGate.attach(servoPin, 1000, 2000);
  startingGate.write(0);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("Drag Race Timer");
  lcd.setCursor(0, 1);
  lcd.print("Push to start!");

  while (digitalRead(buttonPin) == HIGH)
  {
  }

  lcd.clear();
  lcd.print("Go!");

  startingGate.write(180);
  startTime = millis();
}

void loop()
{
  //read the finish sensors at the same time
  finishSensor1 = analogRead(finishSensor1Pin);
  finishSensor2 = analogRead(finishSensor2Pin);
  if (finishFlag == false)
  {
    //car #1 crosses first
    if ((finishSensor1 < darkThreshold) && (finishSensor2 > darkThreshold))
    {
      stopTime = millis();
      raceTime = stopTime - startTime;
      finishFlag = true;

      lcd.clear();
      lcd.print("Winner is Car #1");
      lcd.setCursor(0, 1);
      lcd.print("Time: ");
      lcd.print(raceTime / 1000, 3);
    }
    //car #2 crosses first
    else if ((finishSensor2 < darkThreshold) && (finishSensor1 > darkThreshold))
    {
      stopTime = millis();
      raceTime = stopTime - startTime;
      finishFlag = true;

      lcd.clear();
      lcd.print("Winner is Car #2");
      lcd.setCursor(0, 1);
      lcd.print("Time: ");
      lcd.print(raceTime / 1000, 3);
    }
  }
}
