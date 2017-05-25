/********************************************************************************
   Arduino Inventor's Guide - Project 7 (Listing 7-4)
   Desktop Greenhouse  
  
   Converting from volts to temperature
  
   Written by: Derek Runberg & Brian Huang, July 2016
   SparkFun Electronics & No Starch Press
 *******************************************************************************/
int rawSensorValue;
float rawVolts;
float tempC;
float tempF;

void setup() 
{  
  Serial.begin(9600);  //initializes the serial communication
  Serial.print("raw");
  Serial.print("\t");  //tab character
  Serial.print("volts");
  Serial.print("\t");
  Serial.print("degC");
  Serial.print("\t");
  Serial.print("degF");
  
  Serial.println();    //new line character
}
void loop()
{
  rawSensorValue = analogRead(A0);
  rawVolts = volts(rawSensorValue);  //convert sensor value
                                     //to volts
  tempC = 100 * rawVolts - 50;   //convert volts to deg. C
  tempF = 1.8 * tempC + 32;      //convert deg. C to deg. F
  
  Serial.print (rawSensorValue);  //print raw sensor value
  Serial.print("\t");
  Serial.print (rawVolts);  //print raw voltage reading 

  Serial.print("\t");
  Serial.print(tempC);
  Serial.print("\t");
  Serial.print(tempF);

  Serial.println();         //new line character
  delay(1000);
}

/**************************************************************************/
float volts(int rawCount)
{
   float AREF = 5.0;
   float calculatedVolts;
   calculatedVolts = rawCount * AREF / 1023;
   return calculatedVolts;
}

