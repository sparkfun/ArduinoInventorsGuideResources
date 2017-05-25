/********************************************************************************
   Arduino Inventor's Guide - Project 10 (Listing 10-1)
   Tiny Electric Piano - Serial Tone Test Example

   Upload this example and then open the Serial Monitor. Type in frequencies
   to play.

   Written by: Derek Runberg & Brian Huang, April 2017
   SparkFun Electronics & No Starch Press
 *******************************************************************************/
int freq;
void setup()
{
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  Serial.println("Type in a frequency to play.");
}
void loop()
{
  if (Serial.available() > 0) //wait for a serial
                              //input string
  {
    freq = Serial.parseInt();  //parse out integer value
    Serial.print("Playing note: ");  //user feedback
    Serial.println(freq);
    tone(9, freq, 500);  //play the note for 500 ms
    delay(500);  //delay for the note duration
  }
  else
  {
    noTone(9);
  }
}

