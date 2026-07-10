// E5: PWM (Fade do LED)
// Controla brilho do LED via PWM

const int LED_PIN = 2; // suporta PWM (verificar pinout)

void setup() {
  // Nada necessário — PWM é configurado no loop
}

void loop() {
  // Fade in: 0 → 255 (5 segundos)
  for (int brilho = 0; brilho <= 255; brilho++) {
    analogWrite(LED_PIN, brilho);
    delay(20); // 255 × 20ms = 5.1s
  }
  
  // Fade out: 255 → 0 (5 segundos)
  for (int brilho = 255; brilho >= 0; brilho--) {
    analogWrite(LED_PIN, brilho);
    delay(20);
  }
}
