#define BLYNK_TEMPLATE_ID "TMPL4LfQujhPQ"
#define BLYNK_TEMPLATE_NAME "first"
#define BLYNK_AUTH_TOKEN "5BHGonHODT5oC0Bno458FTW2RAfM9iXV"

#include <WiFi.h>
#include <HTTPClient.h>
#include <BlynkSimpleEsp32.h>

const char* ssid = "home";
const char* password = "12041981sm";

String serverUrl = "http://192.168.0.48:3000/data";
String serverHost = "192.168.0.48";
int serverPort = 3000;
String lastValue = "0";

unsigned long lastSendTime = 0;
const unsigned long sendInterval = 20000;

void setup() {
  Serial.begin(9600);
  delay(4000);
  Serial2.begin(9600, SERIAL_8N1, 16, 17);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
 // connectToWifi();
 Serial.println("System Ready");
}


void sendToBlynk() {

  Blynk.virtualWrite(V0, lastValue);
  Serial.println("Sent to Blynk: " + lastValue);
  
}

void connectToWifi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  //
  Serial.println("Connecting: ");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.print("\nConnected ESP IP:");
  Serial.println(WiFi.localIP());
}


void loop() {
   Blynk.run();

  // Читаємо дані з Serial2, якщо вони є
  if (Serial2.available()) {
    lastValue = Serial2.readString();
    lastValue.trim();
     if (lastValue.length() > 0) {
        Serial.print("Received light: [");
        Serial.print(lastValue);
        Serial.println("]");
    }
  }

  // Відправка в Blynk за таймером (незалежно від Serial)
  if (millis() - lastSendTime >= sendInterval) {
    if (Blynk.connected()) {
      Blynk.virtualWrite(V0, lastValue);
      Serial.println("Sent to Blynk: " + lastValue);
    }
    lastSendTime = millis();
  }
}