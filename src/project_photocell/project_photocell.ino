int photocellPin = A1; 
int photocellReading; 
int LEDpin = 5; 
int LEDbrightness; 
void setup(void) {
Serial.begin(9600);
}
void loop(void) {
 photocellReading = analogRead(photocellPin);
 Serial.print("Analog reading = ");
 Serial.println(photocellReading); 

  if(photocellReading >=1000){
    digitalWrite(LEDpin, HIGH);
 delay(500);
  }
  else{
    digitalWrite(LEDpin, LOW);
  }

}