/********************************************************************************
   Arduino Inventor's Guide - Project 4 (Listing 4-7)
   Reaction Timer

   Connect LEDs to pin 12, 11, 10, and 9 as speed indicators  
   Upload this skecth and then open up the Serial Monitor (CTRL+SHIFT+M).
   
   Written by: Derek Runberg & Brian Huang, March 2016
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
  //sets pins 12, 11, 10, and 9 as OUTPUTs for the indicator
  //bar graph
  pinMode(12, OUTPUT); 
  pinMode(11, OUTPUT); 
  pinMode(10, OUTPUT); 
  pinMode(9, OUTPUT); 
  
  pinMode(3, INPUT);   //sets pin 3 as an INPUT for the
                       //button
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

  //loop to wait until button is pressed
  while(digitalRead(3) == HIGH) 
  { 
  }

  reactTime = millis() - startTime; //calculation of 
                                    //reaction time
  
  digitalWrite(13, LOW);  //turn off LED!

  if (reactTime <= 215)
  {
    digitalWrite(12, HIGH);  
    digitalWrite(11, HIGH);   
    digitalWrite(10, HIGH);   
    digitalWrite(9, HIGH);   
  }
  else if (reactTime <= 250)
  {
    digitalWrite(12, LOW);   
    digitalWrite(11, HIGH);  
    digitalWrite(10, HIGH);  
    digitalWrite(9, HIGH);  
  }
  else if (reactTime <= 300)
  {
    digitalWrite(12, LOW);   
    digitalWrite(11, LOW);  
    digitalWrite(10, HIGH);  
    digitalWrite(9, HIGH);  
  }
  else
  {
    digitalWrite(12, LOW);   
    digitalWrite(11, LOW);  
    digitalWrite(10, LOW);  
    digitalWrite(9, HIGH);  
  }
  
  //display information to Serial Monitor 
  Serial.print("Nice job! Your reaction time was");
  Serial.print(reactTime);
  Serial.println("milliseconds");
  delay(1000);    //short delay before starting again 
}
