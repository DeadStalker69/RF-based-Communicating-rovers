#include <VirtualWire.h>

void setup()
{
  
  pinMode(5,OUTPUT);   //left motors forward
pinMode(6,OUTPUT);   //left motors reverse
pinMode(9,OUTPUT);   //right motors forward
pinMode(11,OUTPUT);   //right motors reverse 
Serial.begin(9600);
    vw_set_rx_pin(3);
    vw_setup(2000);
    pinMode(3, INPUT);
    vw_rx_start();
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN; 
 
    if (vw_get_message(buf, &buflen))
    {
      if(buf[0]=='f')
      {  
    digitalWrite(9,HIGH);
      digitalWrite(5,HIGH);
      }  
      else if(buf[0]=='b')
      {
    digitalWrite(6,HIGH);
    digitalWrite(11,HIGH);
      }
      
      else if(buf[0]=='l')
      {
        
  digitalWrite(9,HIGH);
      }
      
      else if(buf[0]=='r')
      {
          digitalWrite(5,HIGH);
      }
      
      else if(buf[0]=='s')
      {
          digitalWrite(9,LOW);
  digitalWrite(6,LOW);
  digitalWrite(5,LOW);
  digitalWrite(11,LOW);
      }
      }

    }
   
