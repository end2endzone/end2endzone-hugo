//Using RcReceiverSignal v1.1.203
//required to read the receiver's value
//available at http://www.end2endzone.com/rcreceiversignal-an-arduino-library-for-retreiving-the-rc-transmitter-value-from-an-rc-receiver-pulse/
#include <RcReceiverSignal.h>

//Using PinChangeInt version 2402
//RcReceiverSignal library has a dependency to PinChangeInt library.
//available at http://code.google.com/p/arduino-pinchangeint/
#include <PinChangeInt.h>

//Using eRCaGuy_Timer2_Counter version 20140709 (last updated 9 July 2014)
//Required to have a micros() replacement function which has a 
//1us resolution instead of 4usec.
//For more information on this library, see the following:
// http://electricrcaircraftguy.com/2014/02/Timer2Counter-more-precise-Arduino-micros-function.html
// http://www.instructables.com/id/How-to-get-an-Arduino-micros-function-with-05us-pr/
#include <eRCaGuy_Timer2_Counter.h>

//project's constants
#define RECEIVER_AUX1_IN_PIN 2 // we could choose any pin

//project's switches
#define ENABLE_SERIAL_OUTPUT

//*****************************************************************************
//  TODO: UNCOMMENT ONE OF THE FOLLOWING:
//****************************************************************************/
//#define _4X2POS
//#define _3X2POS1X3POS
//#define _3X3POS

DECLARE_RECEIVER_SIGNAL(receiver_aux1_handler);

inline short clamp(const short & iMin, const short & iValue, const short & iMax) {
  if (iValue < iMin)
    return iMin;
  if (iValue > iMax)
    return iMax;
  return iValue;
}

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

void demultiplex3x2Pos1x3Pos(const short & iSignal, unsigned char & oSwitchA, bool & oSwitchB, bool & oSwitchC, bool & oSwitchD) {
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

void demultiplex3x3Pos(const short & iSignal, unsigned char & oSwitchA, unsigned char & oSwitchB, unsigned char & oSwitchC) {
  #define setSwitches(c,b,a) oSwitchA=a; oSwitchB=b; oSwitchC=c;
       if ( -134 <= iSignal && iSignal <=  -125 ) { setSwitches( 0 , 0 , 0 ) }
  else if ( -124 <= iSignal && iSignal <=  -115 ) { setSwitches( 0 , 0 , 1 ) }
  else if ( -114 <= iSignal && iSignal <=  -105 ) { setSwitches( 0 , 0 , 2 ) }
  else if ( -104 <= iSignal && iSignal <=   -95 ) { setSwitches( 0 , 1 , 0 ) }
  else if (  -94 <= iSignal && iSignal <=   -85 ) { setSwitches( 0 , 1 , 1 ) }
  else if (  -84 <= iSignal && iSignal <=   -75 ) { setSwitches( 0 , 1 , 2 ) }
  else if (  -74 <= iSignal && iSignal <=   -65 ) { setSwitches( 0 , 2 , 0 ) }
  else if (  -64 <= iSignal && iSignal <=   -55 ) { setSwitches( 0 , 2 , 1 ) }
  else if (  -54 <= iSignal && iSignal <=   -45 ) { setSwitches( 0 , 2 , 2 ) }
  else if (  -44 <= iSignal && iSignal <=   -35 ) { setSwitches( 1 , 0 , 0 ) }
  else if (  -34 <= iSignal && iSignal <=   -25 ) { setSwitches( 1 , 0 , 1 ) }
  else if (  -24 <= iSignal && iSignal <=   -15 ) { setSwitches( 1 , 0 , 2 ) }
  else if (  -14 <= iSignal && iSignal <=    -5 ) { setSwitches( 1 , 1 , 0 ) }
  else if (   -4 <= iSignal && iSignal <=     5 ) { setSwitches( 1 , 1 , 1 ) }
  else if (    6 <= iSignal && iSignal <=    15 ) { setSwitches( 1 , 1 , 2 ) }
  else if (   16 <= iSignal && iSignal <=    25 ) { setSwitches( 1 , 2 , 0 ) }
  else if (   26 <= iSignal && iSignal <=    35 ) { setSwitches( 1 , 2 , 1 ) }
  else if (   36 <= iSignal && iSignal <=    45 ) { setSwitches( 1 , 2 , 2 ) }
  else if (   46 <= iSignal && iSignal <=    55 ) { setSwitches( 2 , 0 , 0 ) }
  else if (   56 <= iSignal && iSignal <=    65 ) { setSwitches( 2 , 0 , 1 ) }
  else if (   66 <= iSignal && iSignal <=    75 ) { setSwitches( 2 , 0 , 2 ) }
  else if (   76 <= iSignal && iSignal <=    85 ) { setSwitches( 2 , 1 , 0 ) }
  else if (   86 <= iSignal && iSignal <=    95 ) { setSwitches( 2 , 1 , 1 ) }
  else if (   96 <= iSignal && iSignal <=   105 ) { setSwitches( 2 , 1 , 2 ) }
  else if (  106 <= iSignal && iSignal <=   115 ) { setSwitches( 2 , 2 , 0 ) }
  else if (  116 <= iSignal && iSignal <=   125 ) { setSwitches( 2 , 2 , 1 ) }
  else if (  126 <= iSignal && iSignal <=   135 ) { setSwitches( 2 , 2 , 2 ) }
  else {
    setSwitches(0,0,0);
  }
  #undef setSwitches
}

uint32_t timer2GetCountWrapperFunction() {
  return timer2.get_count();
}

void setup() {
  //configure Timer2
  timer2.setup(); //this MUST be done before the other Timer2_Counter functions work; Note: since this messes up PWM outputs on pins 3 & 11, as well as 
                  //interferes with the tone() library (http://arduino.cc/en/reference/tone), you can always revert Timer2 back to normal by calling 
                  //timer2.unsetup()

  //configure RcReceiverSignal with an external time counter
  //eRCaGuy_Timer2_Counter lirary has 0.5us resolution.
  //The counter value must be divided by 2 to convert from 0.5us steps to 1us steps
  //which results in microseconds resolution.
  RcReceiverSignal::setExternalTimeCounter(&timer2GetCountWrapperFunction, 1, 2);

  //link RcReceiverSignal to use PinChangeInt library
  RcReceiverSignal::setAttachInterruptFunction(&PCintPort::attachInterrupt);
  RcReceiverSignal::setPinStatePointer(&PCintPort::pinState);

  #ifdef ENABLE_SERIAL_OUTPUT
    Serial.begin(115200);
    Serial.println("ready");
  #endif

  receiver_aux1_handler_setup(RECEIVER_AUX1_IN_PIN);
}

void loop() {
  //detect when the receiver AUX1 value has changed
  if (receiver_aux1_handler.hasChanged())
  {
    unsigned long pwmValue = receiver_aux1_handler.getPwmValue();
    RcReceiverSignal::VALUE signal = receiver_aux1_handler.getSignalValue(pwmValue);

    char buffer[100];

#ifdef _4X2POS
    bool switchA = false;
    bool switchB = false;
    bool switchC = false;
    bool switchD = false;
    demultiplex4x2Pos(signal, switchA, switchB, switchC, switchD);

    //print switches state
    sprintf(buffer, "PWM=%04d s=%04d  A=%d B=%d C=%d D=%d", 
                      (int)pwmValue,
                      (int)signal,
                      switchA,
                      switchB,
                      switchC,
                      switchD);
#endif 
#ifdef _3X2POS1X3POS
    unsigned char switchA = 0;
    bool switchB = false;
    bool switchC = false;
    bool switchD = false;
    demultiplex3x2Pos1x3Pos(signal, switchA, switchB, switchC, switchD);

    //print switches state
    sprintf(buffer, "PWM=%04d s=%04d  A=%d B=%d C=%d D=%d", 
                      (int)pwmValue,
                      (int)signal,
                      switchA,
                      switchB,
                      switchC,
                      switchD);
#endif
#ifdef _3X3POS
    unsigned char switchA = 0;
    unsigned char switchB = 0;
    unsigned char switchC = 0;
    demultiplex3x3Pos(signal, switchA, switchB, switchC);

    //print switches state
    sprintf(buffer, "PWM=%04d s=%04d  A=%d B=%d C=%d", 
                      (int)pwmValue,
                      (int)signal,
                      switchA,
                      switchB,
                      switchC);
#endif
    Serial.println(buffer);
  }
}
