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
