#define LED_PIN 2  // ברוב לוחות ESP32 זה ה-LED המובנה

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  delay(200);
  Serial.println("ESP32 Blink OK");
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("ON");
  delay(500);

  digitalWrite(LED_PIN, LOW);
  Serial.println("OFF");
  delay(500);
}