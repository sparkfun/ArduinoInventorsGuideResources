/********************************************************************************   
   Arduino Inventor's Guide - Project 9 (Listing 9-1)  
   Drag Race Timer
  
   Liquid Crystal Display (LCD) Test - Displays simple text to the LCD 
   and shows a running timer in seconds.  
  
   Written by: Derek Runberg & Brian Huang, February 2017
   SparkFun Electronics & No Starch Press
 *******************************************************************************/
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

void setup()
{
  lcd.begin(16, 2);  //initializes interface to LCD
  lcd.clear();
  lcd.print("SparkFun Arduino");
}

void loop()
{
  lcd.setCursor(0, 1);       //move cursor to the 2nd line
                             //(col 0, row 1)
  lcd.print(millis()/ 1000); //print the number of
                             //seconds elapsed
}


