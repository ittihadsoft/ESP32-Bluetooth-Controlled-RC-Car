#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

int MotorLeft1 = 12;   //motor2 
int MotorLeft2 = 14;   //motor2 
int MotorRight1 = 27;   //motor2 
int MotorRight2 = 26;   //motor2 
char bt;
/*------------------------------------------------------------------------------*/ 
void setup(){
  Serial.begin(115200);
  SerialBT.begin("ESP32 Car"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  pinMode(MotorLeft1,OUTPUT); 
  pinMode(MotorLeft2,OUTPUT); 
  pinMode(MotorRight1,OUTPUT); 
  pinMode(MotorRight2,OUTPUT); 
} 

void loop(){

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    bt = SerialBT.read();
    Serial.write(bt);
  }  

  switch(bt) {
    case 'f':
    digitalWrite(MotorLeft1,HIGH);
    digitalWrite(MotorLeft2,LOW);
    digitalWrite(MotorRight1,HIGH);
    digitalWrite(MotorRight2,LOW);
  break;
  case 'b':
    digitalWrite(MotorLeft1,LOW);
    digitalWrite(MotorLeft2,HIGH);
    digitalWrite(MotorRight1,LOW);
    digitalWrite(MotorRight2,HIGH);
  break;
  case 'r':
    digitalWrite(MotorLeft1,HIGH);
    digitalWrite(MotorLeft2,LOW);
    digitalWrite(MotorRight1,LOW);
    digitalWrite(MotorRight2,HIGH);
  break;
  case 'l':
    digitalWrite(MotorLeft1,LOW);
    digitalWrite(MotorLeft2,HIGH);
    digitalWrite(MotorRight1,HIGH);
    digitalWrite(MotorRight2,LOW);
  break;
  case 's':
    digitalWrite(MotorLeft1,LOW);
    digitalWrite(MotorLeft2,LOW);
    digitalWrite(MotorRight1,LOW);
    digitalWrite(MotorRight2,LOW);
  }
}