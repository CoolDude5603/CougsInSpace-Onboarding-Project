#include "Wire.h"
#define address 0x60

void setup(){
  Wire.begin();
  Serial.begin(9600);
}

void getdata(byte *a, byte *b){
  
  Wire.beginTransmission(address);
  Wire.write(0); 
  Wire.endTransmission(); 

  Wire.requestFrom(address, 2);
  *a = Wire.read();
  *b = Wire.read();
}

void showdata(){
  byte aa,bb;
  getdata(&aa,&bb);
  
  Serial.println(aa);
  Serial.println(bb);
  delay(1000);
}

void loop(){
  showdata();
}
