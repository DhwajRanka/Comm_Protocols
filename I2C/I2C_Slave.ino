#include <Wire.h>  //Library for I2C Communication functions
int recdata;  //define received data 

void setup()
{
  Serial.begin(9600);  //set baud rate
  Wire.begin(2);  //    //Begins I2C communication with Slave Address as 6 at pin (A4,A5)
  Wire.onReceive(myFunc);  //Function call when Slave receives value from master
}

void myFunc(int something) //This Function is called when Slave receives value from master
{
  recdata=Wire.read(); //Used to read value received from master and store in variable recdata
  //Serial.println(recdata); 
}
void loop()
{
  Serial.println(recdata); //print value of pot reading on serial monitor
}
