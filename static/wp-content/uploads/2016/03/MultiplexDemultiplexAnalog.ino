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

DECLARE_RECEIVER_SIGNAL(receiver_aux1_handler);

inline short clamp(const short & iMin, const short & iValue, const short & iMax) {
  if (iValue < iMin)
    return iMin;
  if (iValue > iMax)
    return iMax;
  return iValue;
}

void demultiplexAnalog40_1x2Pos1x3Pos(const short & iSignal, unsigned char & oAnalogA, bool & oSwitch2, unsigned char & oSwitch3) {
  #define setSwitches(effectiveMin,signal,effectiveMax,a,b) oAnalogA=clamp(effectiveMin,signal,effectiveMax) - (effectiveMin); oSwitch2=a; oSwitch3=b;
       if ( -150 <= iSignal && iSignal <= -105 ) { setSwitches( -147 ,iSignal, -108, 0, 0 ) }
  else if ( -104 <= iSignal && iSignal <=  -59 ) { setSwitches( -101 ,iSignal,  -62, 0, 1 ) }
  else if (  -58 <= iSignal && iSignal <=  -13 ) { setSwitches(  -55 ,iSignal,  -16, 0, 2 ) }
  else if (  -12 <= iSignal && iSignal <=   33 ) { setSwitches(   -9 ,iSignal,   30, 1, 0 ) }
  else if (   34 <= iSignal && iSignal <=   79 ) { setSwitches(   37 ,iSignal,   76, 1, 1 ) }
  else if (   80 <= iSignal && iSignal <=  125 ) { setSwitches(   83 ,iSignal,  122, 1, 2 ) }
  else
  {
    setSwitches( 0,0,0,0,0 );
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

    unsigned char analogA = 0;
    bool switch2 = 0;
    unsigned char switch3 = 0;
    demultiplexAnalog40_1x2Pos1x3Pos(signal, analogA, switch2, switch3);

    //print switches state
    sprintf(buffer, "PWM=%04d s=%04d  analogA=%2d A=%d B=%d", 
                      (int)pwmValue,
                      (int)signal,
                      analogA,
                      switch2,
                      switch3);
    Serial.println(buffer);
  }
}
