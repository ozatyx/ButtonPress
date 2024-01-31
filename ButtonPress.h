//Adapted from the circuitbasics.com tutorial on making classes: https://www.circuitbasics.com/programming-with-classes-and-objects-on-the-arduino/
#ifndef ButtonPress_h
#define ButtonPress_h
#include "Arduino.h" 

class ButtonPress{
  public:
          ButtonPress(int pin);
          bool onOff();
  


  private:
          int _pin;
          int state;
          int lastState;
          unsigned long lastDebounceTime = 0;
          unsigned long debounceDelay = 200;
          bool isOn = false;
};

#endif
