#include "Eventually.h"
#include "MyAnalog.h"
/*
 * This is the standard blinky lights written using Eventually.
 * Just set LIGHT_PIN to whatever pin you have your LED attached to.
 */

#define LIGHT_PIN 13

EvtManager managerEvent;
MyAnalog my_analog;
bool state = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(LIGHT_PIN, OUTPUT);

  
  managerEvent.addListener(new EvtTimeListener(200, true, (EvtAction)blinkme)); 
  managerEvent.addListener(new EvtTimeListener(1000, true, (EvtAction)(my_analog.readADC1())));
  managerEvent.addListener(new EvtTimeListener(2000, true, (EvtAction)my_analog.readADC2()));
}

bool blinkme() {
  state = !state; // Switch light states
  digitalWrite(LIGHT_PIN, state); // Display the state
  return false; // Allow the event chain to continue
}


void loop()
{
  managerEvent.loopIteration();
}























//bool readAnalog1()
//{
//   float valueA = analogRead(A0);
//   Serial.print("value of analog A0 = ");
//   Serial.println(valueA);
//}
//
//bool readAnalog2()
//{
//   float valueA = analogRead(A2);
//   Serial.print("value of analog A2 = ");
//   Serial.println(valueA);
//}


//bool managerADC()
//{
//  static bool switch1 = false;
//  switch1 = !switch1;
//
//  if(switch1) 
//  {
//      managerEvent.addListener(evtAdc1);
//      managerEvent.removeListener(evtAdc2);
//  }
//  else 
//  {
//    managerEvent.addListener(evtAdc2);
//    managerEvent.removeListener(evtAdc1);
//  }
//}
