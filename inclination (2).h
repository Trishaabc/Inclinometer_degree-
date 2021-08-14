#ifdef Inclination_h
#define Inclination_h

#include "Arduino.h"
 class Inclination
 {
  public:
  Inclination(int channel_pin1,int channel_pin2);
  void readAnalog_voltage();
  void readAngle();
  
  private:
  int channel_pin1;
  int channel_pin2;
  };
 #endif
