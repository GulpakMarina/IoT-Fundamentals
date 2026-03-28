// Визначення частот для нот (аналог pitches.h)
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659

const int buzzerPin = 3; // Пін, до якого підключено зумер

// Мелодія приспіву "The Final Countdown"
int melody[] = {
  NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, 0, // Такт 1
  NOTE_C5, NOTE_B4, NOTE_C5, NOTE_B4, NOTE_A4, 0, // Такт 2
  NOTE_C5, NOTE_B4, NOTE_C5, NOTE_E4, 0, // Такт 3
  NOTE_A4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_A4, 0, // Такт 4
  NOTE_G4, 0 // Фінальна нота
};

// Тривалість нот: 4 = чверть, 8 = восьма, 16 = шістнадцята
int noteDurations[] = {
  16, 16, 4, 4, 8,
  16, 16, 8, 8, 4, 8,
  16, 16, 4, 4, 8,
  16, 16, 8, 8, 8, 8, 8,
  4, 2
};

int volume = 5;   

void setup() {
}

void loop() {
  playMelody();
}

void playTone(int pin, int frequency, int duration, int vol) {
  if (frequency == 0) {
    delay(duration);
    return;
  }
  
  long period = 1000000L / frequency; // Період у мікросекундах
  long pulseWidth = (period * vol) / 255; // Ширина імпульсу визначає гучність
  long startTime = millis();

  while (millis() - startTime < duration) {
    digitalWrite(pin, HIGH);
    delayMicroseconds(pulseWidth);
    digitalWrite(pin, LOW);
    delayMicroseconds(period - pulseWidth);
  }
}

void playMelody() {
  for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(int); thisNote++) {
    // Обчислення тривалості ноти в мілісекундах
    int noteDuration = 1000 / noteDurations[thisNote];
    
    if (melody[thisNote] == 0) {
      delay(noteDuration); // Пауза
    } else {
      //tone(buzzerPin, melody[thisNote], noteDuration);
      playTone(buzzerPin, melody[thisNote], noteDuration,volume);
      // Пауза між нотами для чіткості (30% від тривалості)
      int pauseBetweenNotes = noteDuration * 1.40;
      delay(pauseBetweenNotes);
      
      noTone(buzzerPin); // Зупинка звуку
    }
  }
}

