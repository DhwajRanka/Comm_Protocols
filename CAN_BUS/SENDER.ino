//Sender

#include <SPI.h>
#include <mcp2515.h>
byte val;
int sensor = 0;
struct can_frame myMsg;
MCP2515 mcp2515(10);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();
  myMsg.can_dlc=2;
  myMsg.can_id=0xCF;
}

void loop() {
  sensor=analogRead(A0);
  myMsg.data[0]=sensor/256; // we sending two bytes, first one the quotient and the other the remainder and combine it on receiver side.
  myMsg.data[1]=sensor%256;
  mcp2515.sendMessage(&myMsg);
  delayMicroseconds(100);
}
