#ifndef MY_ANALOG_H
#define MY_ANALOG_H
#include <Arduino.h>

#ifndef DEBUG
#define DEBUG true
#endif


class MyAnalog{
  
  public:
  
    MyAnalog(){};
   
    bool readADC1()
    {
       float valueA = analogRead(A0);
       if(DEBUG)
       {
          Serial.print("value of analog A0 = ");
          Serial.println(valueA);
       }
       return false;
    }

    bool readADC2()
    {
       float valueA = analogRead(A2);
       if(DEBUG)
       {
          Serial.print("value of analog A2 = ");
       Serial.println(valueA);
       }
       return false;
    }
  
};



#endif
