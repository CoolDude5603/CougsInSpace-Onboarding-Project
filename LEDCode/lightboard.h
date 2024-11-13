// Header declaring our class: lightboard
#ifndef LIGHTBOARD_H
#define LIGHTBOARD_H
#include "Arduino.h"
#include <Wire.h>

class LightBoard {
  public:
    LightBoard(int sensorPin, int led1, int led2, int led3, int led4);
    void shouldBeOn();
    void setInsAndOuts();
  private:
    const int _lightThreshold = 0; // Naming convention for private variables is an underscore before the name
    int _LEDs[4];
    int _sensorPin;
};

#endif
