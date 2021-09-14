#include <PinChangeInt.h>
#include <eRCaGuy_Timer2_Counter.h>

#include "C:\Users\antoine\Documents\Arduino\libraries\ReceiverSignal\ReceiverSignal.h"
#include "C:\Users\antoine\Documents\Arduino\libraries\ReceiverSignal\ReceiverSignal.cpp"

//project's contants
#define RECEIVER_AUX1_IN_PIN 2 // we could choose any pin
#define BUFFER_SIZE 250

//project's switches
#define ENABLE_SERIAL_OUTPUT

DECLARE_RECEIVER_SIGNAL(receiver_aux1_handler);
unsigned long readingsBuffer[BUFFER_SIZE];
unsigned long numReadings = 0;

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

    //add value to reading buffer
    readingsBuffer[numReadings] = pwmValue;
    numReadings++;

    if (numReadings == BUFFER_SIZE)
    {
      //flush
      #ifdef ENABLE_SERIAL_OUTPUT
        char pwnStr[10];
        unsigned long sum = 0;
        for(unsigned long i=0; i<BUFFER_SIZE; i++)
        {
          pwmValue = readingsBuffer[i];
          sum += pwmValue;
          sprintf(pwnStr, "PWM=%04d", pwmValue);
          Serial.println(pwnStr);
        }
        double avg = sum/double(BUFFER_SIZE);
        Serial.print("sum=");
        Serial.println(sum);
        Serial.print("avg=");
        Serial.println(avg);
      #endif

      numReadings = 0;

      //ignore the next change since serial printing may have impacted the timing...
      while( !receiver_aux1_handler.hasChanged() )
      {
      }
      
    }
  }
}

