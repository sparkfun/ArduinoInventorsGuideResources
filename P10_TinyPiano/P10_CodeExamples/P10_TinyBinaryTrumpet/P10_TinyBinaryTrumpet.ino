/********************************************************************************
   Arduino Inventor's Guide - Project 10 (BONUS)
   Tiny Binary Trumpet

   Uses four buttons -- 3 to specify the note, and the fourth to play it.
   Notes are indexed using binary sequences.

   Written by: Derek Runberg & Brian Huang, April 2017
   SparkFun Electronics & No Starch Press
 *******************************************************************************/
int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 524};
int sensorValue;
byte note;

void setup()
{
  //setup four buttons as INPUTS with internal PULL_UP resistors
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(9, OUTPUT);
}

void loop()
{
  //The variable note is calculated by converting the button presses into 
  //a binary value from 000 to 111. This is a nifty trick - each button 
  //is scaled by a factor of 2^n. The first button is multiplied by 2^0 = 1, 
  //the second button value is multiplied by 2^1 = 2, and the third is 
  //multiplied by 2^2 = 4. Adding these up is how you convert from 
  //binary to decimal.

  note = 1 * digitalRead(4) + 2 * digitalRead(3) + 4 * digitalRead(2);

 if (digitalRead(5) == LOW)
  {
    //note is then used to index the frequency array to play the tone.
    tone(9, frequencies[note]);
  }
  else
  {
    noTone(9);
  }
}

