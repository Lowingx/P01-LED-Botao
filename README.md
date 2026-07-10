# P01 — LED + Botão

> Primeiro circuito: LED piscando com botão. A base de tudo.

## O Que É

Projeto introdutório de eletrônica e programação embarcada. Montar um circuito onde um botão controla um LED, usando ESP32.

**Por que importa:** Todo sistema BCI é essencialmente: ler entrada → processar → atuar. Este projeto é essa pilha em miniatura.

## Materiais

| Item | Qtd | Onde Comprar |
|------|-----|--------------|
| ESP32 DevKit v1 | 1 | Mercado Livre, AliExpress (~R$35) |
| Protoboard 830 pontos | 1 | Mercado Livre (~R$15) |
| LEDs (vermelho/verde) | 5+ | Mercado Livre (~R$5) |
| Resistores 220Ω e 10kΩ | 10+ | Mercado Livre (~R$5) |
| Botão táctil | 2 | Mercado Livre (~R$3) |
| Jumpers macho-macho | 20+ | Mercado Livre (~R$10) |
| Multímetro básico | 1 | Mercado Livre (~R$50) |

**Total estimado: ~R$123**

## Etapas

### E1: LED Estático
```
5V → Resistor 220Ω → LED (+) → LED (-) → GND
```

### E2: Blink com ESP32
```cpp
const int LED_PIN = 2;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
}
```

### E3: Botão com Pull-Down
```cpp
const int BOTAO_PIN = 4;
const int LED_PIN = 2;

void setup() {
  pinMode(BOTAO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(BOTAO_PIN) == HIGH) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(10);
}
```

### E4: Debounce em Software
```cpp
const int BOTAO_PIN = 4;
const int LED_PIN = 2;
unsigned long ultimoToggle = 0;
bool estadoLed = false;

void setup() {
  pinMode(BOTAO_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  if (digitalRead(BOTAO_PIN) == LOW) {
    unsigned long agora = millis();
    if (agora - ultimoToggle > 50) {
      estadoLed = !estadoLed;
      digitalWrite(LED_PIN, estadoLed ? HIGH : LOW);
      ultimoToggle = agora;
    }
  }
}
```

### E5: PWM (Fade)
```cpp
const int LED_PIN = 2;

void loop() {
  for (int brilho = 0; brilho <= 255; brilho++) {
    analogWrite(LED_PIN, brilho);
    delay(20);
  }
  for (int brilho = 255; brilho >= 0; brilho--) {
    analogWrite(LED_PIN, brilho);
    delay(20);
  }
}
```

## Status

- [ ] E1: LED Estático
- [ ] E2: Blink com ESP32
- [ ] E3: Botão com Pull-Down
- [ ] E4: Debounce em Software
- [ ] E5: PWM (Fade)

## Tech Stack

![Arduino](https://img.shields.io/badge/Arduino-0a0805?style=for-the-badge&logo=arduino&logoColor=c9a227&labelColor=0a0805)
![C++](https://img.shields.io/badge/C++-0a0805?style=for-the-badge&logo=cplusplus&logoColor=c9a227&labelColor=0a0805)
![ESP32](https://img.shields.io/badge/ESP32-0a0805?style=for-the-badge&logo=espressif&logoColor=c9a227&labelColor=0a0805)
