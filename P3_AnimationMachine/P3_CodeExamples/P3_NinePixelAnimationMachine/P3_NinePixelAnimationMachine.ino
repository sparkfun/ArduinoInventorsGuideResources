/********************************************************************************
   Arduino Inventor's Guide - Project 3 (Complete Sketch)
   Nine-Pixel Animation Machine

    LED Array is setup in this arrangement
    13 ---- 12 ---- 11
    10 ---- 9 ----- 8
     7 ---- 6 ----- 5

   Written by: Derek Runberg & Brian Huang, February 2016
   SparkFun Electronics & No Starch Press
 *******************************************************************************/

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  //blink between x and 0 characters
  xChar();
  delay(500);
  oChar();
  delay(500);

  //uncomment for random pixel animation, used as an example for going further
  //randomPixel();

  //uncomment for a rotating "linux wait cursor", covered in the creating animations
  //spinningLine(200);
}

/********************************************************************************
  //display an 'X' character on the 3x3 LED matrix
  /********************************************************************************/
void xChar()
{
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
}

/********************************************************************************
  //display an 'O' character on the 3x3 LED matrix
  /********************************************************************************/
void oChar()
{
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
}

/********************************************************************************
   display a veritcal line in the center of the 3x3 LED matrix
 ********************************************************************************/
void verticalLine()
{
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);

  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);

  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(5, LOW);
}

/********************************************************************************
   display a diagonal line from the top left in the center of the 3x3 LED matrix
 ********************************************************************************/
void topLeftDiagonal()
{
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);

  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);

  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
}

/********************************************************************************
   display a horizontal line in the center of the 3x3 LED matrix
 ********************************************************************************/
void horizontalLine()
{
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);

  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);

  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
}

/********************************************************************************
   display a diagonal line from the top right in the center of the 3x3 LED matrix
 ********************************************************************************/
void topRightDiagonal()
{
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);

  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);

  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
}

/********************************************************************************
   turn a random LED ON and then turns a random LED OFF
 ********************************************************************************/
void randomPixel()
{
  digitalWrite(random(5, 13), HIGH);
  delay(500);
  digitalWrite(random(5, 13), LOW);
  delay(500);
}

/********************************************************************************
   display a spinning line on the 3x3 LED matrix
 ********************************************************************************/
void spinningLine(int delayTime)
{
  verticalLine();
  delay(delayTime);

  topLeftDiagonal();
  delay(delayTime);

  horizontalLine();
  delay(delayTime);

  topRightDiagonal();
  delay(delayTime);
}

/********************************************************************************
   display an triangle on the 3x3 LED matrix
 ********************************************************************************/
void triangle()
{
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
}

