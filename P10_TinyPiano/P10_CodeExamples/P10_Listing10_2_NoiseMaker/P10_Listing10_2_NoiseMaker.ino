/********************************************************************************
   Arduino Inventor's Guide - Project 10 (Listing 10-2)
   Tiny Electric Piano - Noisemaker Example

   Upload this example and then open the Serial Monitor,
   and then squeeze the SoftPot to make some noise!

   Written by: Derek Runberg & Brian Huang, April 2017
   SparkFun Electronics & No Starch Press
 *******************************************************************************/
int sensorValue;
void setup()
{
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  sensorValue = analogRead(A0);
  if (sensorValue > 0)   //if there's a press on sensor,
                         //play note
  {
    Serial.print("Raw sensor reading: ");
    Serial.println(sensorValue);
    tone(9, sensorValue, 50);
    delay(50);
  }
  else
  {
    noTone(9);
  }
}

