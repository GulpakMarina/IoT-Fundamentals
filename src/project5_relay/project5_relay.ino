int relayPin = 12; 
void setup () {
 pinMode (relayPin, OUTPUT); 
}
void loop () {
//  while(!digitalRead(buttonPin)){
    	digitalWrite(relayPin, HIGH);
      delay(500);
      	digitalWrite(relayPin, LOW);
      delay(500);

  
  
 }