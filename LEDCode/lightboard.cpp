#include "lightboard.h"

LightBoard::LightBoard(int sensorPin, int led1, int led2, int led3, int led4) {
  _sensorPin = sensorPin;
  _LEDs[1] = led1;
  _LEDs[2] = led2;
  _LEDs[3] = led3;
  _LEDs[4] = led4;
}

void LightBoard::shouldBeOn(){
  int rawLight = analogRead(_sensorPin);
  int light = map(rawLight, 0, 1023, 0, 100);
  if (light > _lightThreshold){
    for (int i = 0; i < 4; i++){
      digitalWrite(_LEDs[i], HIGH);
    }
  } 
  else {
    for (int i = 0; i < 4; i++){
      digitalWrite(_LEDs[i], LOW);
    }
  }
}

void LightBoard::setInsAndOuts() {
  pinMode(_sensorPin, INPUT);
  for(int i = 0; i < 4; i++) {
    pinMode(_LEDs[i], OUTPUT);
  }
}