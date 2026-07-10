// E2: Blink com ESP32
// LED pisca a 1 Hz (500ms ligado, 500ms desligado)

const int LED_PIN = 2; // LED embutido no ESP32

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("Blink iniciado!");
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500); // 500ms ligado
  
  digitalWrite(LED_PIN, LOW);
  delay(500); // 500ms desligado
}
