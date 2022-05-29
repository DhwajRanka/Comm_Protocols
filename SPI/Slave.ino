//Slave

#include<SPI.h>  
volatile bool flag1 = false;
volatile bool flag2 = false;
volatile byte c;

byte i = 0;
volatile byte j = 0;
byte arr[11];

void setup (void)
{
  Serial.begin (9600);
  pinMode(MISO, OUTPUT);
  SPCR |= _BV(SPE);
  SPCR |= _BV(SPIE);
}

void loop (void)
{
  if (flag2 == true)
  {
    for (int k = 0; k < 11; k++)
    {
      Serial.print(arr[k]);
    }
    Serial.println();
    Serial.println("================");
    flag1 = false;
    flag2 = false;
    j = 0;
  }
}


ISR (SPI_STC_vect)
{
  c = SPDR;
  if (flag1 == false)
  {
    if (c == 0xCD)
    {
      SPDR = 0xEF;
      flag1 = true;
    }
  }
  else
  {
    arr[j] = c;
    j++;
    if (j == 10)
    {
      flag2 = true;
    }
  }
}
