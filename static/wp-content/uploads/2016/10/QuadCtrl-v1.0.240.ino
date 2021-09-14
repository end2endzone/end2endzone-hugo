//
//  QuadCtrl - Quadcopter Controller - v1.0 - 10/07/2016
//  Copyright (C) 2016 Antoine Beauchamp
//  The code & updates for the library can be found on http://end2endzone.com
//
// AUTHOR/LICENSE:
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 3.0 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License (LGPL-3.0) for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
//
// DISCLAIMER:
//  This software is furnished "as is", without technical support, and with no 
//  warranty, express or implied, as to its usefulness for any purpose.
//
// PURPOSE:
//  The following code implements Buzzer & LED functionnalities to my 
//  personnal quadcopter.
//
//  The buzzer is activated to play RTTTL melodies played before takeoff
//  and after landing. The buzzer is also used to play a mayday distress
//  signal that can be used to recover the quadcopter after an unexpected
//  crash.
//
//  The front-facing 10w LED is used to know the orientation of the quadcopter
//  from a far point of view. To prevent the LED from draining the battery,
//  the LED is flashing at specific rates.
//  The rates can be modulated from 40 positions varrying from always OFF
//  to always ON in a 2 second cycle. ie: a rate of 24/40 (60%) turns the
//  LED ON for 1200ms and OFF for 800ms.
//
//  Both functionalities are activated through my SPEKTRUM DX9
//  transmitter using a rotary knob, a 2-position switch and a 3-position
//  switch sending a signal to my Orange R620X DSMX2 receiver.
//
//  The receiver is connected to arduino pin 2 to read PWM signals sent
//  by the receiver.
//
//  The code is indented to run on an arduino nano v3.
//
// HISTORY:
// 10/07/2016 v1.0 - Initial release of QuadCtrl.
//
// ---------------------------------------------------------------------------



/*************************************************
 * PinChangeInt code optimizations
 *************************************************/
//http://www.benripley.com/diy/arduino/three-ways-to-read-a-pwm-signal-with-arduino/
//https://github.com/GreyGnome/PinChangeInt/wiki/Usage
//http://playground.arduino.cc/Learning/Pins
//#define NO_PIN_STATE        // to indicate that you don't need the PCintPort::pinState
#define NO_PIN_NUMBER         // to indicate that you don't need the PCintPort::arduinoPin
#define PINMODE               // defines PCintPort::pinMode which is 
#define NO_PORTC_PINCHANGES   // only port D pinchanges (see: http://playground.arduino.cc/Learning/Pins)
#define NO_PORTB_PINCHANGES   // only port B pinchanges (see: http://playground.arduino.cc/Learning/Pins)

//required libraries

//Using SoftTimers v1.1.219
//Required to calculate the LED's ON and OFF times.
//Available at http://www.end2endzone.com/softtimers-a-collection-of-software-timers-to-easily-compute-elapsed-time-since-an-event-occured/
#include <SoftTimers.h>

//Using RcReceiverSignal v1.2.203
//Required to read PWM signals sent from the RC Receiver.
#include <RcReceiverSignal.h>

//Using PinChangeInt version 2402
//RcReceiverSignal library has a dependency to PinChangeInt library.
#include <PinChangeInt.h>

//Using eRCaGuy_Timer2_Counter version 20140709 (last updated 9 July 2014)
//Required to have a micros() replacement function which has a 
//1us resolution instead of 4usec.
//For more information on this library, see the following:
// http://electricrcaircraftguy.com/2014/02/Timer2Counter-more-precise-Arduino-micros-function.html
// http://www.instructables.com/id/How-to-get-an-Arduino-micros-function-with-05us-pr/
#include <eRCaGuy_Timer2_Counter.h>

//Using AnyRtttl v2.1 - 06/05/2016
//Required to play RTTTL data
#include <anyrtttl.h>
#include <binrtttl.h>
#include <pitches.h>

//project's constants
#define RECEIVER_AUX1_IN_PIN 2 // we could choose any pin
#define LED_DEBUG_OUT_PIN 13
#define LED_OUT_PIN 9
#define BUZZER_OUT_PIN 8
#define LED_FREQUENCY_LENGTH 1000 //in ms
#define ANALOG_VALUE_MIN 0
#define ANALOG_VALUE_MAX 39
#define ANALOG_VALUE_THRESHOLD 3
#define DISABLE_RTTTL_PLAYBACK false

//project's switches
//#define ENABLE_SERIAL_OUTPUT

DECLARE_RECEIVER_SIGNAL(receiver_aux1_handler);
SoftTimer onTimer;
SoftTimer offTimer;
SoftTimer melodyInhibit; //prevents to consecutive RTTTL melodies to play one after the other
SoftTimer alarmTimer;
uint16_t ledOnTime = 0; //ms
uint16_t ledOffTime = LED_FREQUENCY_LENGTH; //ms
bool ledOn = true;
bool alarmOverride = false;  //controlled by a 2-position switch
uint8_t playMelody = false;  //controlled by a 3-position switch

inline int16_t clamp(const int16_t & iMin, const int16_t & iValue, const int16_t & iMax) {
  if (iValue < iMin)
    return iMin;
  if (iValue > iMax)
    return iMax;
  return iValue;
}

/*
 * Desription:
 *  Demultiplex the following from an RcReceiverSignal value:
 *  - an analog knob value (which has a resolution of 40 steps, values from 0 to 39)
 *  - a 2-position switch
 *  - a 3-position switch
 *  
 *  Code sample from http://www.end2endzone.com/how-to-multiplex-rc-transmitter-switches-into-a-single-channel/#Decoding-2
 *  
 *  The following mixes must be used on a Spektrum DX9 to multiplex all switches into AUX1:
 *  - RKnob > AX1,   high=-74%, low=  0%, offset=-99%
 *  - RKnob > AX1,   high=  0%, low= 54%, offset=100%
 *  - SwitchA > AX1, high=  0%, low=-69%, offset=100%
 *  - SwitchB > AX1, high=  0%, low=-46%, offset=100%
 *  
 */
void demultiplexAnalog40_1x2Pos1x3Pos(const int16_t & iSignal, uint8_t & oAnalogA, bool & oSwitch2, uint8_t & oSwitch3) {
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

/*
void debugLED() {
  while (true)
  {
    digitalWrite(LED_OUT_PIN, HIGH);
    digitalWrite(LED_DEBUG_OUT_PIN, HIGH);
    delay(1000);
    digitalWrite(LED_OUT_PIN, LOW);
    digitalWrite(LED_DEBUG_OUT_PIN, LOW);
    delay(1000);
  }
}
*/

#ifdef ENABLE_SERIAL_OUTPUT
//pretty print buffer
char ppBuffer[10];

char * prettyPrint(const char * format, const uint16_t & value)
{
  sprintf(ppBuffer, format, value);
  return ppBuffer;
}
char * prettyPrint(const char * format, const int16_t & value)
{
  sprintf(ppBuffer, format, value);
  return ppBuffer;
}
#endif

/*************************************************
 * RTTTL Melodies
 *************************************************/
#define NUM_RTTTL_MELODY 14
const char simpsons[]           PROGMEM = "simpsons:d=4,o=5,b=160:c.6,e6,f#6,8a6,g.6,e6,c6,8a,8f#,8f#,8f#,2g,8p,8p,8f#,8f#,8f#,8g,a#.,8c6,8c6,8c6,c6";
const char arkanoid[]           PROGMEM = "Arkanoid:d=4,o=5,b=140:8g6,16p,16g.6,2a#6,32p,8a6,8g6,8f6,8a6,2g6";
const char cocacola[]           PROGMEM = "Coca-cola:d=4,o=5,b=125:8f#6,8f#6,8f#6,8f#6,g6,8f#6,e6,8e6,8a6,f#6,d6,2p";
const char pacman[]             PROGMEM = "pacman:d=4,o=5,b=112:32b,32p,32b6,32p,32f#6,32p,32d#6,32p,32b6,32f#6,16p,16d#6,16p,32c6,32p,32c7,32p,32g6,32p,32e6,32p,32c7,32g6,16p,16e6,16p,32b,32p,32b6,32p,32f#6,32p,32d#6,32p,32b6,32f#6,16p,16d#6,16p,32d#6,32e6,32f6,32p,32f6,32f#6,32g6,32p,32g6,32g#6,32a6,32p,32b.6";
const char mario_short[]        PROGMEM = "smb_short:d=16,o=5,b=180:e.,e.,p.,e.,p.,c.,e.,p.,g.,4p,g.4";
const char mario_death[]        PROGMEM = "smbdeath:d=4,o=5,b=90:32c6,32c6,32c6,8p,16b,16f6,16p,16f6,16f.6,16e.6,16d6,16c6,16p,16e,16p,16c";
const char mario_flagpole[]     PROGMEM = "smbflagpole:d=32,o=6,b=112:f#.4,c.5,e.5,g.5,c.,e.,8g,8e,g#.4,c.5,d#.5,g#.5,c.,d#.,8g#,8d#,a#.4,d.5,f.5,a#.5,d.,f.,8a#,b.,b.,b.,4c7";
const char mario_gameover[]     PROGMEM = "smbgameover:d=8,o=4,b=180:16c.5,16p.,16p.,16g.,p.,e.,a,b,a,g#,a#,g#,16g.,16f.,g.";
const char mario_1up[]          PROGMEM = "smb1up:d=16,o=7,b=180:e.6,g.6,e.,c.,d.,g.";
const char starwars_cantina[]   PROGMEM = "SWCantina:d=4,o=5,b=250:8a,8p,8d6,8p,8a,8p,8d6,8p,8a,8d6,8p,8a,8p,8g#,a,8a,8g#,8a,g,8f#,8g,8f#,f.,8d.,16p,p.,8a,8p,8d6,8p,8a,8p,8d6,8p,8a,8d6,8p,8a,8p,8g#,8a,8p,8g,8p,g.,8f#,8g,8p,8c6,a#,a,g";
const char tetris[]             PROGMEM = "tetris:d=4,o=5,b=160:e6,8b,8c6,8d6,16e6,16d6,8c6,8b,a,8a,8c6,e6,8d6,8c6,b,8b,8c6,d6,e6,c6,a,2a,8p,d6,8f6,a6,8g6,8f6,e6,8e6,8c6,e6,8d6,8c6,b,8b,8c6,d6,e6,c6,a,a";
const char topgun[]             PROGMEM = "TopGun:d=4,o=4,b=31:32p,16c#,16g#,16g#,32f#,32f,32f#,32f,16d#,16d#,32c#,32d#,16f,32d#,32f,16f#,32f,32c#,16f,16d#";
const char backtothefuture[]    PROGMEM = "bttf:d=4,o=5,b=100:c#4,g#.4,8c#,b.4,16a#4,16g#4,8a#.4,8g#.4,8f#4,g#.4,16g#4,16g#4,2g#.4,c#,g#.,8c#6,b.,16a#,16g#,8a#.,8g#.,8f#,1g#";
const char bond[]               PROGMEM = "bond:d=4,o=5,b=125:8e,16f#,16f#,8f#,f#,8e,8e,8e,8e,16g,16g,8g,g,8f#,8f#,8f#,8e,16f#,16f#,8f#,f#,8e,8e,8e,8e,16g,16g,8g,g,8f#,8f#,8f#,8e,16f#,16f#,8f#,f#,8e,8e,8e,8e,16g,16g,8g,g,8f#,8f,8e,8e6,2d6,8p,8b,8a,2b";

void playRtttl(uint8_t iPinNumber, const char * iBuffer) {
  //are we allowed to play another melody ?
  //is it too soon ?
  if (melodyInhibit.hasTimedOut() || melodyInhibit.getTimeOutTime()==0)
  {
    //fine play another melody

    //disable interrupts. timer2 messes up with the tone() library
    noInterrupts();
    timer2.revert_to_normal();
    interrupts();

    //play
    anyrtttl::blocking::playProgMem(iPinNumber, iBuffer);

    //enable interrupts. Configure timer2 again for 0.5us resolution.
    noInterrupts();
    timer2.setup();
    interrupts();

    //disable RTTTL playback for 100ms to allow RcReceiverSignal to
    //read the new update since the code was blocking during playback
    melodyInhibit.setTimeOutTime(500);
    melodyInhibit.reset();
  }
  else
  {
    #ifdef ENABLE_SERIAL_OUTPUT
    Serial.print(F("Too soon for playing again. Please wait "));
    Serial.print(melodyInhibit.getRemainingTime());
    Serial.print(F("ms..."));
    #endif
  }
}

uint32_t timer2GetCountWrapperFunction() {
  return timer2.get_count();
}

void setup() {
  pinMode(LED_OUT_PIN, OUTPUT);
  pinMode(LED_DEBUG_OUT_PIN, OUTPUT);
  pinMode(BUZZER_OUT_PIN, OUTPUT);

  //play booting melody
  playRtttl(BUZZER_OUT_PIN, arkanoid);

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

  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  uint16_t seed = analogRead(0);
  randomSeed(seed);

  //allow the first RTTTL melody to be played
  melodyInhibit.setTimeOutTime(0);

  //configure alarm loop count time
  alarmTimer.setTimeOutTime(50);

  #ifdef ENABLE_SERIAL_OUTPUT
    Serial.begin(115200);
    Serial.println(F("ready"));
    Serial.print(F("seed="));
    Serial.println(seed);
  #endif

  receiver_aux1_handler_setup(RECEIVER_AUX1_IN_PIN);

  onTimer.reset();
}

void processBuzzerPinUpdate()
{
  if (alarmOverride)
  {
    int count = alarmTimer.getLoopCount() % 29;
    bool pinHigh = (count ==  0 || 
                    count ==  2 || 
                    count ==  4 || 
                    count == 16 || 
                    count == 17 || 
                    count == 18 );
    if (pinHigh)
      digitalWrite(BUZZER_OUT_PIN, HIGH);
    else
      digitalWrite(BUZZER_OUT_PIN, LOW);
  }
  else if (playMelody != 0) //is 1 or 2
  {
    //debuging mode: Temporary disable RTTTL playback
    if (DISABLE_RTTTL_PLAYBACK)
      return;
    
    // print a random number from 0 to NUM_RTTTL_MELODY-1
    int32_t melodyIndex = random(0, NUM_RTTTL_MELODY);

    #ifdef ENABLE_SERIAL_OUTPUT
    Serial.print(F("melodyIndex="));
    Serial.println(melodyIndex);
    #endif

    switch(melodyIndex)
    {
    case 0:
      playRtttl(BUZZER_OUT_PIN, simpsons);
      break;
    case 1:
      playRtttl(BUZZER_OUT_PIN, arkanoid);
      break;
    case 2:
      playRtttl(BUZZER_OUT_PIN, cocacola);
      break;
    case 3:
      playRtttl(BUZZER_OUT_PIN, pacman);
      break;
    case 4:
      playRtttl(BUZZER_OUT_PIN, mario_short);
      break;
    case 5:
      playRtttl(BUZZER_OUT_PIN, mario_death);
      break;
    case 6:
      playRtttl(BUZZER_OUT_PIN, mario_flagpole);
      break;
    case 7:
      playRtttl(BUZZER_OUT_PIN, mario_gameover);
      break;
    case 8:
      playRtttl(BUZZER_OUT_PIN, mario_1up);
      break;
    case 9:
      playRtttl(BUZZER_OUT_PIN, starwars_cantina);
      break;
    case 10:
      playRtttl(BUZZER_OUT_PIN, tetris);
      break;
    case 11:
      playRtttl(BUZZER_OUT_PIN, topgun);
      break;
    case 12:
      playRtttl(BUZZER_OUT_PIN, backtothefuture);
      break;
    case 13:
      playRtttl(BUZZER_OUT_PIN, bond);
      break;
    default:
      #ifdef ENABLE_SERIAL_OUTPUT
      Serial.print(F("ERROR WITH RTTTL MELODY."));
      #endif
      break;
    };
  }
  else
  {
    digitalWrite(BUZZER_OUT_PIN, LOW);
  }
}

void processAux1SignalChanged()
{
  uint16_t pwnValue = receiver_aux1_handler.getPwmValue();
  RcReceiverSignal::VALUE signalValue = receiver_aux1_handler.getDeviceSignalValue(SPEKTRUM_DX9_ORANGE_R620X, pwnValue);

  uint8_t analogKnob = 0;
  demultiplexAnalog40_1x2Pos1x3Pos(signalValue, analogKnob, alarmOverride, playMelody);

  //default to always OFF
  ledOnTime = 0; //ms
  ledOffTime = LED_FREQUENCY_LENGTH; //ms

  /*
   * Note:
   *  Since the RcReceiverSignal may flicker a little (oscillate from 0 to 2),
   *  the first 3 analog values must be considered OFF. This allows the pilot
   *  to easily set the LED always OFF (without blimps).
   *  
   *  Also consider last 2 analog values as always ON. This allows the pilot
   *  to easily set the LED always ON (without blimps).
   */
  if (analogKnob < ANALOG_VALUE_THRESHOLD)
  {
    //force always OFF
    analogKnob = 0;
  }
  else if (analogKnob >= ANALOG_VALUE_MAX-1)
  {
    //force always ON
    analogKnob = ANALOG_VALUE_MAX;
  }

  //map signal value to an on-time and off-time
  ledOnTime = map(analogKnob, 0, ANALOG_VALUE_MAX, 0, LED_FREQUENCY_LENGTH); //ms
  ledOffTime = LED_FREQUENCY_LENGTH - ledOnTime; //ms

  //update timers
  onTimer.setTimeOutTime(ledOnTime);
  offTimer.setTimeOutTime(ledOffTime);

  #ifdef ENABLE_SERIAL_OUTPUT
    Serial.print(F("signal="));
    Serial.print(prettyPrint("%4d", signalValue));
    Serial.print(F("% PWM="));
    Serial.print(prettyPrint("%04d", pwnValue));
    Serial.print(F(" analog="));
    Serial.print(prettyPrint("%02d", analogKnob));
    Serial.print(F(" buzzerOverride="));
    Serial.print(buzzerOverride);
    Serial.print(F(" playMelody="));
    Serial.print(playMelody);
    Serial.print(F(" ON:"));
    Serial.print(prettyPrint("%04d", ledOnTime));
    Serial.print(F(" OFF:"));
    Serial.print(prettyPrint("%04d", ledOffTime));
    Serial.println();
  #endif
}

void processLedPinUpdate()
{
  if (ledOn)
  {
    //led is ON

    //should it be turned OFF ?
    if (onTimer.hasTimedOut() && offTimer.getTimeOutTime() > 0)
    {
      //time to turn OFF the LED
      digitalWrite(LED_OUT_PIN, LOW);
      digitalWrite(LED_DEBUG_OUT_PIN, LOW);
      ledOn = !ledOn;
      offTimer.reset();
    }
  }
  else
  {
    //led is OFF

    //should it be turned ON ?
    if (offTimer.hasTimedOut() && onTimer.getTimeOutTime() > 0)
    {
      //time to turn ON the LED
      digitalWrite(LED_OUT_PIN, HIGH);
      digitalWrite(LED_DEBUG_OUT_PIN, HIGH);
      ledOn = !ledOn;
      onTimer.reset();
    }
  }
}

void loop() {
  //detect when the receiver AUX1 value has changed
  if (receiver_aux1_handler.hasChanged())
  {
    processAux1SignalChanged();
  }

  //check timers if required to toggle
  processLedPinUpdate();

  //update buzzer
  processBuzzerPinUpdate();
}
