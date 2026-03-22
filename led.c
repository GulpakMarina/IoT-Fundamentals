int redLED = 7;
int yellowLED = 4;
int whiteLED = 2;

int buttonPin = 8;

int state = 0;

bool lastButtonState = LOW;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);

  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {

  bool buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {
    
    state++;

    if (state > 3) {
      state = 0;
    }

    updateLEDs();
  }

  lastButtonState = buttonState;
}

void updateLEDs() {
  switch (state - 1 ) {
    case 2: digitalWrite(yellowLED, LOW); break;
    case 1: digitalWrite(redLED, LOW); break;
    case -1:
    case 0: digitalWrite(whiteLED, LOW); break;
  }


  switch (state) {
    case 1: digitalWrite(redLED, HIGH); break;
    case 2: digitalWrite(yellowLED, HIGH); break;
    case 3: digitalWrite(whiteLED, HIGH); break;
  }
}