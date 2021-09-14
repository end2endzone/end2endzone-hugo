#include <PinChangeInt.h>
#include <eRCaGuy_Timer2_Counter.h>

#include "C:\Users\antoine\Documents\Arduino\libraries\ReceiverSignal\ReceiverSignal.h"
#include "C:\Users\antoine\Documents\Arduino\libraries\ReceiverSignal\ReceiverSignal.cpp"

//project's contants
#define RECEIVER_AUX1_IN_PIN 2 // we could choose any pin

//project's switches
#define ENABLE_SERIAL_OUTPUT

DECLARE_RECEIVER_SIGNAL(receiver_aux1_handler);

void demultiplex4x2Pos(const short & iSignal, bool & oSwitchA, bool & oSwitchB, bool & oSwitchC, bool & oSwitchD) {
  #define setSwitches(d,c,b,a) oSwitchA=(a==1); oSwitchB=(b==1); oSwitchC=(c==1); oSwitchD=(d==1);

       if ( -150 <= iSignal && iSignal <=  -141 ) { setSwitches( 0 , 0 , 0 , 0 ) }
  else if ( -140 <= iSignal && iSignal <=  -131 ) { setSwitches( 0 , 0 , 0 , 1 ) }
  else if ( -130 <= iSignal && iSignal <=  -121 ) { setSwitches( 0 , 0 , 1 , 0 ) }
  else if ( -120 <= iSignal && iSignal <=  -111 ) { setSwitches( 0 , 0 , 1 , 1 ) }
  else if ( -110 <= iSignal && iSignal <=  -101 ) { setSwitches( 0 , 1 , 0 , 0 ) }
  else if ( -100 <= iSignal && iSignal <=   -91 ) { setSwitches( 0 , 1 , 0 , 1 ) }
  else if (  -90 <= iSignal && iSignal <=   -81 ) { setSwitches( 0 , 1 , 1 , 0 ) }
  else if (  -80 <= iSignal && iSignal <=   -71 ) { setSwitches( 0 , 1 , 1 , 1 ) }
  else if (  -70 <= iSignal && iSignal <=   -61 ) { setSwitches( 1 , 0 , 0 , 0 ) }
  else if (  -60 <= iSignal && iSignal <=   -51 ) { setSwitches( 1 , 0 , 0 , 1 ) }
  else if (  -50 <= iSignal && iSignal <=   -41 ) { setSwitches( 1 , 0 , 1 , 0 ) }
  else if (  -40 <= iSignal && iSignal <=   -31 ) { setSwitches( 1 , 0 , 1 , 1 ) }
  else if (  -30 <= iSignal && iSignal <=   -21 ) { setSwitches( 1 , 1 , 0 , 0 ) }
  else if (  -20 <= iSignal && iSignal <=   -11 ) { setSwitches( 1 , 1 , 0 , 1 ) }
  else if (  -10 <= iSignal && iSignal <=    -1 ) { setSwitches( 1 , 1 , 1 , 0 ) }
  else if (    0 <= iSignal && iSignal <=     9 ) { setSwitches( 1 , 1 , 1 , 1 ) }
  else {
    setSwitches(0,0,0,0);
  }
  #undef setSwitches
}

void demultiplex3x2Pos3Pos(const short & iSignal, unsigned char & oSwitchA, bool & oSwitchB, bool & oSwitchC, bool & oSwitchD) {
  #define setSwitches(d,c,b,a) oSwitchA=a; oSwitchB=(b==1); oSwitchC=(c==1); oSwitchD=(d==1);

       if ( -150 <= iSignal && iSignal <=  -141 ) { setSwitches( 0 , 0 , 0 , 0 ) }
  else if ( -140 <= iSignal && iSignal <=  -131 ) { setSwitches( 0 , 0 , 0 , 1 ) }
  else if ( -130 <= iSignal && iSignal <=  -121 ) { setSwitches( 0 , 0 , 0 , 2 ) }
  else if ( -120 <= iSignal && iSignal <=  -111 ) { setSwitches( 0 , 0 , 1 , 0 ) }
  else if ( -110 <= iSignal && iSignal <=  -101 ) { setSwitches( 0 , 0 , 1 , 1 ) }
  else if ( -100 <= iSignal && iSignal <=   -91 ) { setSwitches( 0 , 0 , 1 , 2 ) }
  else if (  -90 <= iSignal && iSignal <=   -81 ) { setSwitches( 0 , 1 , 0 , 0 ) }
  else if (  -80 <= iSignal && iSignal <=   -71 ) { setSwitches( 0 , 1 , 0 , 1 ) }
  else if (  -70 <= iSignal && iSignal <=   -61 ) { setSwitches( 0 , 1 , 0 , 2 ) }
  else if (  -60 <= iSignal && iSignal <=   -51 ) { setSwitches( 0 , 1 , 1 , 0 ) }
  else if (  -50 <= iSignal && iSignal <=   -41 ) { setSwitches( 0 , 1 , 1 , 1 ) }
  else if (  -40 <= iSignal && iSignal <=   -31 ) { setSwitches( 0 , 1 , 1 , 2 ) }
  else if (  -30 <= iSignal && iSignal <=   -21 ) { setSwitches( 1 , 0 , 0 , 0 ) }
  else if (  -20 <= iSignal && iSignal <=   -11 ) { setSwitches( 1 , 0 , 0 , 1 ) }
  else if (  -10 <= iSignal && iSignal <=    -1 ) { setSwitches( 1 , 0 , 0 , 2 ) }
  else if (    0 <= iSignal && iSignal <=     9 ) { setSwitches( 1 , 0 , 1 , 0 ) }
  else if (   10 <= iSignal && iSignal <=    19 ) { setSwitches( 1 , 0 , 1 , 1 ) }
  else if (   20 <= iSignal && iSignal <=    29 ) { setSwitches( 1 , 0 , 1 , 2 ) }
  else if (   30 <= iSignal && iSignal <=    39 ) { setSwitches( 1 , 1 , 0 , 0 ) }
  else if (   40 <= iSignal && iSignal <=    49 ) { setSwitches( 1 , 1 , 0 , 1 ) }
  else if (   50 <= iSignal && iSignal <=    59 ) { setSwitches( 1 , 1 , 0 , 2 ) }
  else if (   60 <= iSignal && iSignal <=    69 ) { setSwitches( 1 , 1 , 1 , 0 ) }
  else if (   70 <= iSignal && iSignal <=    79 ) { setSwitches( 1 , 1 , 1 , 1 ) }
  else if (   80 <= iSignal && iSignal <=    89 ) { setSwitches( 1 , 1 , 1 , 2 ) }
  else {
    setSwitches(0,0,0,0);
  }
  #undef setSwitches
}


void setup() {
  //configure Timer2
  timer2.setup(); //this MUST be done before the other Timer2_Counter functions work; Note: since this messes up PWM outputs on pins 3 & 11, as well as 
                  //interferes with the tone() library (http://arduino.cc/en/reference/tone), you can always revert Timer2 back to normal by calling 
                  //timer2.unsetup()

#ifdef ENABLE_SERIAL_OUTPUT
  Serial.begin(115200);
#endif

  receiver_aux1_handler_setup(RECEIVER_AUX1_IN_PIN);
}

void loop() {
  //detect when the receiver AUX1 value has changed
  if (receiver_aux1_handler.hasChanged())
  {
    unsigned long pwmValue = receiver_aux1_handler.getPwmValue();
    ReceiverSignal::VALUE signal = receiver_aux1_handler.getSignalValue(pwmValue);

    //bool switchA = false;
    //bool switchB = false;
    //bool switchC = false;
    //bool switchD = false;
    //demultiplex4x2Pos(signal, switchA, switchB, switchC, switchD);
    
    unsigned char switchA = 0;
    bool switchB = false;
    bool switchC = false;
    bool switchD = false;
    demultiplex3x2Pos3Pos(signal, switchA, switchB, switchC, switchD);

    //print switches state
    char buffer[100];
    sprintf(buffer, "PWM=%04d s=%04d  A=%d B=%d C=%d D=%d", 
                      (int)pwmValue,
                      (int)signal,
                      switchA,
                      switchB,
                      switchC,
                      switchD);

    Serial.println(buffer);
  }
}

