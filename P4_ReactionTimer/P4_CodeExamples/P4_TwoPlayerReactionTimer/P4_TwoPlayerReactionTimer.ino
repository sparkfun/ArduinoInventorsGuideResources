/********************************************************************************
   Arduino Inventor's Guide - Project 4 (Modify Section)
   Two-Player Reaction Timer

   Connect a push button to pin 2 and a push button to pin 3
   Wait for the LED to light up. First to press wins! No cheating!
   
   Written by: Derek Runberg & Brian Huang, April 2016
   SparkFun Electronics & No Starch Press
 *******************************************************************************/

unsigned int waitTime;   //random wait time before
                         //turning on LED
unsigned int startTime;  //zero reference time
unsigned int reactTime;  //calculated reaction time

void setup()
{
  Serial.begin(9600);  //sets up serial
  pinMode(13, OUTPUT); //sets pin 13 as an OUTPUT for the
                       //stimulus LED
  pinMode(12, OUTPUT); //sets pin 12 as an OUTPUT for the
                       //green LED
  pinMode(11, OUTPUT); //sets pin 11 as an OUTPUT for the
                       //red LED
  pinMode(3, INPUT);   //sets pin 3 as an INPUT for the
                       //button (player 1)
  pinMode(2, INPUT);   //sets pin 2 as an INPUT for the
                       //button (player 2)
}
void loop()
{
  //prints the challenge instructions
  Serial.println("When the LED turns on, push the button!");
  Serial.println("Now, watch the LED. Ready?");
  waitTime = random(2000, 4000); //random wait time
                                 //from 2000 to 4000 ms
  delay(waitTime);  //delay random wait time

  //turn on the LED!
  digitalWrite(13, HIGH);

  startTime = millis();  //set zero time reference

  //loop to wait until either button is pressed
  while ((digitalRead(3) == HIGH) && (digitalRead(2) == HIGH))
  {
  }

  reactTime = millis() - startTime; //calculation of
                                    //reaction time

  digitalWrite(13, LOW);  //turn off LED!

  // indicate a winner
  if (digitalRead(3) == LOW)
  {
    digitalWrite(11, HIGH);
    Serial.print("Winner is Player 1!");
  }
  else if (digitalRead(2) == LOW)
  {
    digitalWrite(12, HIGH);
    Serial.print("Winner is Player 2!");
  }
  
  //display information to Serial Monitor
  Serial.print("Nice job! Your reaction time was");
  Serial.print(reactTime);
  Serial.println("milliseconds");
  delay(1000);    //short delay before starting again
}
