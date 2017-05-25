/********************************************************************************
   Arduino Inventor's Guide - Project 9 (Listing 9-2)
   Drag Race Timer - Single Car

   Uses a button to trigger moving a servo arm up (starting gate) to start the
   race. Timer runs until the light sensor is crossed at the end. 

   Elapsed raceTime is shown on the LCD.

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
const int darkThreshold = 500;

int finishSensor1;
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
  finishSensor1 = analogRead(finishSensor1Pin);
  Serial.println(finishSensor1);
  if ((finishFlag == false) && (finishSensor1 < darkThreshold))
  {
    finishFlag = true;
    stopTime = millis();
    raceTime = stopTime - startTime;

    lcd.clear();
    lcd.print("Finish Time:");
    lcd.setCursor(0, 1);
    lcd.print(raceTime / 1000, 3);
  }
}
