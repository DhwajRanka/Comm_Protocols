//Receiver

#include <SPI.h>
#include <mcp2515.h>
byte recdata[2];

struct can_frame recMsg;
MCP2515 mcp2515(10);
int result;

void setup() {
  SPI.begin();
  Serial.begin(9600);
  mcp2515.reset();
  mcp2515.setBitrate(CAN_500KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();
}

void loop() {
  if (mcp2515.readMessage(&recMsg) == MCP2515::ERROR_OK) {
        if(recMsg.can_id==0xCF)
        {
          recdata[0]=recMsg.data[0];
          recdata[1]=recMsg.data[1];
          result = recdata[0]*256 + recdata[1]; //recombining the data sent by sender 
          Serial.println(result);
          delayMicroseconds(100);
        }
    }
}
