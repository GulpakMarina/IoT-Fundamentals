int ledPin = 5; 
void setup () {
 pinMode (ledPin, OUTPUT); 
}
void loop () {
for (int value = 0; value<255; value = value + 1) {
 analogWrite (ledPin, value); 
 delay (5); 
 }
 for (int value = 255; value>0; value = value-1) {
 analogWrite (ledPin, value);
 delay (5); 
 }
 for (int value = 0; value<6; value = value + 1) {
 digitalWrite (ledPin, HIGH); 
 delay (50); 
  digitalWrite (ledPin, LOW); 
 delay (50); 
 }
 }