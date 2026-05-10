#include <Servo.h>
Servo myServo;  // Create a Servo class object
void setup() {
  myServo.attach(9);  // Connect the servo to the D9 output
  for (int pos = 0; pos <= 180; pos += 1) {
    myServo.write(pos);
    delay(15);  // Delay for smooth movement
  }             // Rotate the servo from 180° to 0°
  for (int pos = 180; pos >= 0; pos -= 1) {
    myServo.write(pos);
    delay(15);
  }
}
void loop() {  // Rotate the servo from 0° to 180°
  
}
