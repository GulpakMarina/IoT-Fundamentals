#include <LiquidCrystal_I2C.h>

int MQ2 = A0;
int val = 0;
int buzzer = 3;

LiquidCrystal_I2C mylcd (0x27,16,2); 

void setup() {
  pinMode(MQ2, INPUT);
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  mylcd.init();
  mylcd.backlight();
  mylcd.clear();
}
void loop() {
  val = analogRead(MQ2);
  Serial.println(val);
  if (val > 450) {
    display("gas!!", val);
    //tone(buzzer, 589);
    delay(300);
  } else {
    display("no gas", val);
    // noTone(buzzer);
  }
}

void display(String msg, int value) {
  mylcd.clear();
  mylcd.setCursor(0, 0);
  mylcd.print("value:");
  mylcd.setCursor(6, 0);
  mylcd.print(value);
  mylcd.setCursor(0, 1);
  mylcd.print(msg);
  delay(300);
}
