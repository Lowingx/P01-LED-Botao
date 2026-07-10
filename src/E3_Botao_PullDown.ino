// E3: Botão com Pull-Down
// Botão liga/desliga o LED

const int BOTAO_PIN = 4;
const int LED_PIN = 2;

void setup() {
  pinMode(BOTAO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int estado = digitalRead(BOTAO_PIN);
  
  if (estado == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Botão pressionado — LED LIGADO");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("Botão solto — LED DESLIGADO");
  }
  
  delay(10); // debounce simples
}
