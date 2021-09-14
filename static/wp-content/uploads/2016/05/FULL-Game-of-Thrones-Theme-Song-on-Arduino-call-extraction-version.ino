////////////////////////////////////////////////////////////////////////
//
//                    GAME OF THRONES THEME SONG
//                PERFORMED ON PIEZO SENSOR AND 3 LEDS
//                           WRITTEN BY 
//                           KALEB HILL
//                            5/28/15
//
////////////////////////////////////////////////////////////////////////

//https://www.youtube.com/watch?v=vrzQU_QbQ5U

int ledred = 9;           // the pin that the LED is attached to
int ledblue = 10;
int ledgreen = 5;
int brightness = 255;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

//project's contants
#define BUZZER_OUT_PIN 8

//silence all analogWrite calls
#define analogWrite dummyAnalogWrite
void dummyAnalogWrite(int pin, int value)
{
}

//output function calls to serial port
void serialTone(byte pin, uint16_t frequency, uint32_t duration) {
  Serial.print("tone(");
  Serial.print(pin);
  Serial.print(",");
  Serial.print(frequency);
  Serial.print(",");
  Serial.print(duration);
  Serial.println(");");
}

void serialNoTone(byte pin) {
  Serial.print("noTone(");
  Serial.print(pin);
  Serial.println(");");
}

void serialDelay(uint32_t duration) {
  Serial.print("delay(");
  Serial.print(duration);
  Serial.println(");");
}

#define tone serialTone
#define delay serialDelay
#define noTone serialNoTone

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  //pinMode(ledred, OUTPUT);
  //pinMode(ledblue, OUTPUT);
  //pinMode(ledgreen, OUTPUT);
  pinMode(BUZZER_OUT_PIN, OUTPUT);

  Serial.begin(115200);
}

// the loop routine runs over and over again forever:

void loop (){
Serial.println("START");
  
  
//G3
analogWrite(ledred, 255);
analogWrite(ledblue, 255);
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);


////////////////////////////////ONE
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

////////////////////////////////TWO
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

//////////////////////////////THREE
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

///////////////////////////////FOUR
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

///////////////////////////////FIVE

//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//E3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 165, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

///////////////////////////////SIX
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

//////////////////////////////SEVEN

//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//E3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 165, 175);
delay(200);
analogWrite(ledblue, LOW); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);
analogWrite(ledred, LOW);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);


//////////////////////////////EIGHT

//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

/////////////////////////////////////////////////CHORUS1////////////////////////////////////////////
  
  
//G4  
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 392, 1175);
delay(1200);
analogWrite(ledred, LOW);

//C4
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 262, 1175);
delay(1200);
analogWrite(ledblue, LOW);

//DS4
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 311, 175);
delay(200);

//F4
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 349, 175);
delay(200);

//G4
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 392, 775);
delay(800);

//C4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 262, 775);
delay(800);

//DS4
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 311, 175);
delay(200);

//F4
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 349, 175);
delay(200);

//////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

///////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);



/////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

/////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);
while(brightness > 0)
  {
  analogWrite(ledred, brightness);
  analogWrite(ledblue, brightness);
  analogWrite(ledgreen, brightness);
  brightness = brightness - fadeAmount;
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
}
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
brightness = 255;
fadeAmount = 5;





//F4
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 349, 1175);
delay(1200);
analogWrite(ledred, LOW);

//AS4
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 233, 1175);
delay(1200);
analogWrite(ledblue, LOW);

//D4
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 294, 175);
delay(200);

//DS4
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 311, 175);
delay(200);

//F4
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 349, 775);
delay(800);

//AS3
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 233, 775);
delay(800);

//DS4
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 311, 175);
delay(200);

//D4
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 294, 175);
delay(200);

//////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

///////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);


/////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

/////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

/////////////////////////////////////////////////CHORUS2////////////////////////////////////////////
  
  
//G5  
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 392, 1175);
delay(1200);
analogWrite(ledred, LOW);

//C4
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 262, 1175);
delay(1200);
analogWrite(ledblue, LOW);

//DS4
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 311, 175);
delay(200);

//F4
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 349, 175);
delay(200);

//G4
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 392, 775);
delay(800);

//C4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 262, 775);
delay(800);

//DS4
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 311, 175);
delay(200);

//F4
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 349, 175);
delay(200);

//////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

///////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);



/////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

/////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);
while(brightness > 0)
  {
  analogWrite(ledred, brightness);
  analogWrite(ledblue, brightness);
  analogWrite(ledgreen, brightness);
  brightness = brightness - fadeAmount;
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
}
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
brightness = 255;
fadeAmount = 5;

//////////////////////////////////////////

//F4
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 349, 1175);
delay(1200);
analogWrite(ledred, LOW);

//AS4
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 233, 1175);
delay(1200);
analogWrite(ledblue, LOW);

//D4
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 294, 175);
delay(200);

//DS4
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 311, 175);
delay(200);

//F4
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 349, 775);
delay(800);

//AS3
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 233, 775);
delay(800);

//DS4
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 311, 175);
delay(200);

//D4
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 294, 175);
delay(200);

//////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

///////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);


/////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

/////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

/////////////////////////////////////////////////CHORUS3////////////////////////////////////////////
  
  
//G5  
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 784, 1175);
delay(1200);
analogWrite(ledred, LOW);

//C5
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 523, 1175);
delay(1200);
analogWrite(ledblue, LOW);

//DS5
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 622, 175);
delay(200);

//F5
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 698, 175);
delay(200);

//G5
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 784, 775);
delay(800);

//C5
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 523, 775);
delay(800);

//DS5
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 622, 175);
delay(200);

//F5
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 698, 175);
delay(200);

//////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

///////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);



/////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

/////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);
while(brightness > 0)
  {
  analogWrite(ledred, brightness);
  analogWrite(ledblue, brightness);
  analogWrite(ledgreen, brightness);
  brightness = brightness - fadeAmount;
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
}
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
brightness = 255;
fadeAmount = 5;


////////////////////////////////


//F5
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 698, 1175);
delay(1200);
analogWrite(ledred, LOW);

//AS4
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 466, 1175);
delay(1200);
analogWrite(ledblue, LOW);

//D5
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 587, 575);
delay(600);

//DS5
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 622, 575);
delay(600);

//D5
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 587, 575);
delay(600);

//AS4
tone(BUZZER_OUT_PIN, 466, 575);
delay(600);

///////////////////////////////

//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

///////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);


/////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

/////////////////////////////
  
//C3
analogWrite(ledred, LOW);  
analogWrite(ledblue, LOW);  
analogWrite(ledgreen, LOW);  
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);
while(brightness > 0)
  {
  analogWrite(ledred, brightness);
  analogWrite(ledblue, brightness);
  analogWrite(ledgreen, brightness);
  brightness = brightness - fadeAmount;
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
}
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
brightness = 255;
fadeAmount = 5;



//////////////////////////////////////////////////////////////////////////////////////////

//C5
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 523, 375);
delay(400);


//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

///////////

//C5
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 523, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);


///////////////////////////////////////////

//AS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 466, 375);
delay(400);

//D3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 147, 175);
delay(200);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200);

//F3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 175, 375);
delay(400);

/////////

//AS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 466, 375);
delay(400);

//D3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 147, 175);
delay(200);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200);

//F3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 175, 375);
delay(400);


//////////////////////////////////////////

//GS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 415, 375);
delay(400);

//C3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 131, 175);
delay(200);

//D3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 147, 175);
delay(200);

//DS3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 156, 375);
delay(400);

//////////

//GS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 415, 375);
delay(400);

//C3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 131, 175);
delay(200);

//D3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 147, 175);
delay(200);

//DS3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 156, 375);
delay(400);


/////////////////////////////////////////

//G4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 392, 375);
delay(400);

//AS2
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 117, 175);
delay(200);

//C3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 131, 175);
delay(200);

//D3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 147, 375);
delay(400);

///////////

//G4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 392, 375);
delay(400);

//AS2
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 117, 175);
delay(200);

//C3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 131, 175);
delay(200);

//D3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 147, 375);
delay(400);


/////////////////////////////////////////

//DS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 311, 375);
delay(400);

//G2
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 98, 175);
delay(200);

//GS2
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 104, 175);
delay(200);

//AS2
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 117, 375);
delay(400);

///////////

//DS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 311, 375);
delay(400);

//G2
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 98, 175);
delay(200);

//GS2
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 104, 175);
delay(200);

//AS2
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 117, 375);
delay(400);


//////////////////////////////////////////

//DS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 311, 375);
delay(400);

//G2
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 98, 175);
delay(200);

//G2
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 98, 175);
delay(200);

//DS4
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 311, 375);
delay(400);

//F4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 349, 775);
delay(400);

//GS2
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 104, 175);
delay(200);

//GS2
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 104, 175);
delay(200);

//F4
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 349, 375);
delay(400);

//////////////////////////////////////////

//C4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 262, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

///////////

//C3
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

//C3
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

//C3
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

//C5
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 523, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

///////////

//C5
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 523, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);


///////////////////////////////////////////

//AS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 466, 375);
delay(400);

//D3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 147, 175);
delay(200);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200);

//F3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 175, 375);
delay(400);

/////////

//AS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 466, 375);
delay(400);

//D3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 147, 175);
delay(200);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200);

//F3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 175, 375);
delay(400);


//////////////////////////////////////////

//GS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 415, 375);
delay(400);

//C3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 131, 175);
delay(200);

//D3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 147, 175);
delay(200);

//DS3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 156, 375);
delay(400);

//////////

//GS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 415, 375);
delay(400);

//C3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 131, 175);
delay(200);

//D3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 147, 175);
delay(200);

//DS3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 156, 375);
delay(400);


/////////////////////////////////////////

//G4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 392, 375);
delay(400);

//AS2
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 117, 175);
delay(200);

//C3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 131, 175);
delay(200);

//D3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 147, 375);
delay(400);

///////////

//G4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 392, 375);
delay(400);

//AS2
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 117, 175);
delay(200);

//C3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 131, 175);
delay(200);

//D3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 147, 375);
delay(400);


/////////////////////////////////////////

//DS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 311, 375);
delay(400);

//G2
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 98, 175);
delay(200);

//GS2
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 104, 175);
delay(200);

//AS2
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 117, 375);
delay(400);

///////////

//DS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 311, 375);
delay(400);

//G2
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 98, 175);
delay(200);

//GS2
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 104, 175);
delay(200);

//AS2
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 117, 375);
delay(400);


//////////////////////////////////////////

//DS4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 311, 775);
delay(800);

//DS4
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 311, 375);
delay(400);

//D4
analogWrite(ledred, LOW);
tone(BUZZER_OUT_PIN, 294, 775);
delay(800);

//D4
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 294, 375);
delay(400);

//////////////////////////////////////////

//C4
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 262, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

///////////

//C3
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

/////////////

//C3
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

////////////

//C3
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

///////////////

//C3
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS3
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 156, 175);
delay(200); 
  
//F3
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 175, 175);
delay(200);

//G3
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 196, 375);
delay(400);

////////////////////////////////////////////////

//C3
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 131, 375);
delay(400);

//DS5
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 622, 175);
delay(200); 
  
//F5
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 698, 175);
delay(200);

//G5
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 784, 375);
delay(400);

/////////////////////////////////////////////////

//C5
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 523, 375);
delay(400);

//DS5
analogWrite(ledred, LOW);
tone(BUZZER_OUT_PIN, 622, 175);
delay(200); 
  
//F5
analogWrite(ledgreen, LOW);
tone(BUZZER_OUT_PIN, 698, 175);
delay(200);

//G5
analogWrite(ledblue, LOW);
tone(BUZZER_OUT_PIN, 784, 375);
delay(400);

/////////////////////////////////////////////////

//C5
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 523, 375);
delay(400);

//DS5
analogWrite(ledblue, 255);
tone(BUZZER_OUT_PIN, 622, 175);
delay(200); 
  
//F5
analogWrite(ledred, 255);
tone(BUZZER_OUT_PIN, 698, 175);
delay(200);

//G5
analogWrite(ledgreen, 255);
tone(BUZZER_OUT_PIN, 784, 375);
delay(400);
while(brightness > 0)
  {
  analogWrite(ledred, brightness);
  analogWrite(ledblue, brightness);
  analogWrite(ledgreen, brightness);
  brightness = brightness - fadeAmount;
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
}
analogWrite(ledred, LOW);
analogWrite(ledgreen, LOW);
analogWrite(ledblue, LOW);
brightness = 255;
fadeAmount = 5;

Serial.println("END");

delay(3000);

while(true) {
}


}
