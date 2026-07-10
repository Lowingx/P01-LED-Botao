// E4: Debounce em Software
// Trata bounce mecânico do botão

const int BOTAO_PIN = 4;
const int LED_PIN = 2;
unsigned long ultimoToggle = 0;
const unsigned long DEBOUNCE_MS = 50;
bool estadoLed = false;

void setup() {
  pinMode(BOTAO_PIN, INPUT_PULLUP); // usar pull-up interno
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if (digitalRead(BOTAO_PIN) == LOW) { // LOW = pressionado (pull-up)
    unsigned long agora = millis();
    if (agora - ultimoToggle > DEBOUNCE_MS) {
      estadoLed = !estadoLed;
      digitalWrite(LED_PIN, estadoLed ? HIGH : LOW);
      ultimoToggle = agora;
      Serial.print("Toggle! LED: ");
      Serial.println(estadoLed ? "LIGADO" : "DESLIGADO");
    }
  }
}
