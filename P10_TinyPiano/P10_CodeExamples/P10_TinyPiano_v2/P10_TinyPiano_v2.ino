/********************************************************************************
   Arduino Inventor's Guide - Project 10 (Modify)
   Tiny Electric Piano - v2 (Multi-octave piano w/ button)

   This example adds a button onto pin 2. Pressing this button increments 
   a state variable "octaveMultiplier". This multiplies all of the frequencies 
   providing you with an extra octave of frequencies. Can you figure out how 
   to modify this to play 3 octaves?

   Written by: Derek Runberg & Brian Huang, April 2017
   SparkFun Electronics & No Starch Press
 *******************************************************************************/
int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 524};
int sensorValue;
byte note;
byte octaveMultiplier = 1;
void setup()
{
  pinMode(2, INPUT_PULLUP);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(A0);
  if (digitalRead(2) == LOW)
  {
    octaveMultiplier = octaveMultiplier + 1;
    if (octaveMultiplier > 2)
    {
      octaveMultiplier = 1;
    }
    while (digitalRead(2) == LOW)
    {}
  }
  if ( sensorValue > 0 )   //if it's a note, play it!
  {
    //Map the key pressed to a note
    note = map(sensorValue, 0, 1023, 0, 8);
    Serial.print(sensorValue);
    Serial.print("\t");
    Serial.println(octaveMultiplier * frequencies[note]);
    tone(9, octaveMultiplier * frequencies[note], 50);
    delay(50);
  }
  else
  {
    noTone(9);
  }
}



