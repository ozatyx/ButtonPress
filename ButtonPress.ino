//Adapted from the circuitbasics.com tutorial on making classes: https://www.circuitbasics.com/programming-with-classes-and-objects-on-the-arduino/
//Debounce code inspired from https://docs.arduino.cc/built-in-examples/digital/Debounce/

#include "Arduino.h"
#include "ButtonPress.h"

ButtonPress::ButtonPress(int pin){
            pinMode(pin, INPUT_PULLUP);
            _pin = pin;
            
}

bool ButtonPress::onOff() {

  state = digitalRead(_pin);
  
  //debounce timer
  if((millis()-lastDebounceTime) > debounceDelay) {

    if(state == LOW && lastState == HIGH){

      while(true){
        
        if(isOn == false){
          isOn = true;
          break;
        }
      
        if(isOn == true){
          isOn = false;
          break;
        }
      }
      
      lastDebounceTime = millis();
    }

    


  }
    
  
  lastState = state;
  return isOn;

  


}
