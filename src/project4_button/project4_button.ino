int ledPin = 5; 
int buttonPin = 4; 
void setup () {
 pinMode (ledPin, OUTPUT); 
 pinMode (buttonPin, INPUT); 
}
void loop () {
  while(!digitalRead(buttonPin)){
    	digitalWrite(ledPin, HIGH);
    //  delay(500);
      	
     // delay(500);

  }
  digitalWrite(ledPin, LOW);
 }