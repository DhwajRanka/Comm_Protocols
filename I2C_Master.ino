//Master

#include <Wire.h>  //Library for I2C Communication functions
#define slave_addr 2  //define slave's address
int sensor;
byte val;

void setup()
{
  Wire.begin(2);  //Begins I2C communication at pin (A4,A5)
  pinMode(A0, INPUT);  
  Serial.begin(9600);   //Begins Serial Communication at 9600 baud rate
}

void loop()
{
  sensor=analogRead(A0);  //analog pin receives value of sensor
  val=map(sensor, 1, 1023, 0, 255);  //Maps 10 bit analog read to 8 bit analog write
  Wire.beginTransmission(slave_addr);  // start transmit to slave arduino (2)

  Wire.write(val);  // sends one byte converted POT value to slave
  Wire.endTransmission();  // stop transmitting
  Serial.println(val);  //Prints in Serial Monitor value of sensor(POT)

}
