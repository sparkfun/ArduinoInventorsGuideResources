/********************************************************************************
   Arduino Inventor's Guide - Project 10 (Listing 10-3)
   Tiny Electric Piano Example Code

   The SoftPot is divided up into 8 equal segments. Press or squeeze the SoftPot
   to play a note that is indexed in the array frequencies[].

   Written by: Derek Runberg & Brian Huang, April 2017
   SparkFun Electronics & No Starch Press
 *******************************************************************************/
int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 524};
int sensorValue;
byte note;

void setup()
{
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(A0);
  if ( sensorValue > 0 )   //if it's a note, play it!
  {
    //map the key pressed to a note
    note = map(sensorValue, 0, 1023, 0, 8);
    note = constrain(note, 0, 7);
    Serial.print(sensorValue);
    Serial.print("\t");
    Serial.println(frequencies[note]);
    tone(9, frequencies[note], 50);
    delay(50);
  }
  else
  {
    noTone(9);
  }
}

