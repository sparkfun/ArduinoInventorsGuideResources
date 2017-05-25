/********************************************************************************
   Arduino Inventor's Guide - Project 6 (Bonus)
   Balance Beam - Auto-Pilot Code

   This is a bonus project added at the end of the chapter. Connect a slide
   switch to pin 12. Setting the slide switch will trigger the "auto balance"
   feature. This uses two for() loops, not yet covered in this part of the
   book. It's a bonus!

   Written by: Derek Runberg & Brian Huang, May 2016
   SparkFun Electronics & No Starch Press
 *******************************************************************************/

#include<Servo.h>
Servo myServo;
int potVal;
int anglePosition;

byte range = 15;  //range of angles for autopilot mode. The servo
                  //will move up and down by this amount from the
                  //center position
byte balancePoint = 90; //nominal balanced angle position (flat)

void setup()
{
  myServo.attach(9);
}

void loop()
{
  //check the switch position. If LOW, allow the pot to control
  //the servo. Else, run the auto-pilot code
  if (digitalRead(12) == LOW)
  {

    potVal = analogRead(A0);
    anglePosition = map(potVal, 0, 1023, 10, 170);
    myServo.write(anglePosition);
    delay(20);
  }
  else
  {
    //Two sets of for() loops increments the variable scaleFactor between
    //-1.0 and +1.0 and back. This is multiplied by the "range" which is the
    //window of angles around the center point. A 20 ms delay provides
    //enough time for the servo to move to this new position.

    for (float scaleFactor = -1.0; scaleFactor < 1; scaleFactor += 0.1)
    {
      anglePosition = scaleFactor * range + balancePoint;
      myServo.write(anglePosition);
      delay(20);
    }

    for (float scaleFactor = 1.0; scaleFactor > -1.0; scaleFactor -= 0.1)
    {
      anglePosition = scaleFactor * range + balancePoint;
      myServo.write(anglePosition);
      delay(20);
    }
  }
}
