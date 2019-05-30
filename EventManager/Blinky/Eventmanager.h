/*
 * This lib base on Eventually lib
 * 
 */



#ifndef EVENMANAGER_H
#define EVENMANAGER_H

#include <limits.h>
#include <Arduino.h>


#define EVENTUALLY_MAX_CONTEXTS 10
#define EVENTUALLY_MAX_LISTENERS 20


class EvtManager;   // Quan ly  su kien
class EvtContext;   // Ngu canh cua Su kien
class EvtListener;  // Lang nghe Su kien (Duoc kich hoat or not)

typedef bool (*EvtAction)(EvtListener *, EvtContext *);  // Define a new type for Event action


class EvtManager {
  public:

    EvtManager();
    void loopIteration();
    EvtContext *pushContext();
    EvtContext *resetContext();
    EvtContext *popContext();

    void addListener(EvtListener *lstn);
    void removeListener(EvtListener *lstn);

  private: 
    EvtContext *contextStack = 0;
    int contextOffset = 0;
    int contextDepth = 0;
};



//======================== CLASS EVENT CONTEXT===============
// Note - should probably expand the number of available listeners by chaining contexts
/*
 * 
 * 
 */
class EvtContex{
  public:
    void *data = 0;  // Luu tru bat cu du lieu gi o day

    EvtContext();
    void setupContext();
    void loopIteration();
    void addListener(EvtListener *lstn);
    void romoveListener(EvtListener *lstn);

  private:
    EvtListener **listeners = 0;
    int listenerCount;
};



//========================EVENT LISTENER ====================
class EvtListener{
  public: 
  void *extraData = 0; // a pointer  chua xac dinh kieu bien. it can be arbitrary variable 
                        // Anything you want to store here
  
  
  virtual void setupListener();
  virtual bool isEventTriggered();
  virtual bool performAction(EventContex *); // return false if I should stop the current chain
  
};


class EvtTimeListener : publish EvtListener {
    public: 
      EvtTimeListener();
      EvtTimeListener(unsigned long time, bool multiFire, EvtAction trigger);
      unsigned long millis;
      void setupListener();
      bool isEventTriggered();
      bool performTriggerAcction(EvtContext *);

    private:
      unsigned long startMillis;
      bool multiFire = false;
      int numFires = 0;
};

#endif
