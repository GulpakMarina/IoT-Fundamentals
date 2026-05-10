#include <SoftwareSerial.h>

// Створюємо програмний UART на пінах 10 (RX) та 11 (TX)
SoftwareSerial bluetooth(10, 11);

void setup() {
  // Ініціалізуємо послідовні порти
  Serial.begin(9600);      // Для монітора порту
  bluetooth.begin(9600);   // Для HM-10

  Serial.println("HM-10 Bluetooth готовий!");
  Serial.println("Очікування підключення...");
}

void loop() {
  // Читаємо дані з Bluetooth і відправляємо в Serial Monitor
  if (bluetooth.available()) {
    String data = bluetooth.readString(); 
      Serial.print("Отримано рядок: ");
    Serial.println(data);
   // Serial.write(c);
  }

  // Читаємо дані з Serial Monitor і відправляємо в Bluetooth
  if (Serial.available()) {
    char c = Serial.read();
    bluetooth.write(c);
  }
}