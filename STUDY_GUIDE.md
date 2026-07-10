# Guia de Estudo — P01 LED + Botão

> O que estudar antes, durante e depois de cada etapa.

---

## ANTES DE COMEÇAR

### Conceitos Fundamentais (ler primeiro)

**1. Eletrônica Básica (30 min)**

Lei de Ohm: `V = I × R`
- V = tensão (volts)
- I = corrente (amperes)
- R = resistência (ohms)

Exemplo: Fonte 5V, LED 2V, resistor 220Ω
```
I = (5V - 2V) / 220Ω = 13.6mA
```

**O que é um LED:**
- Tem polaridade: anodo (+) e catodo (-)
- Anodo: pino mais longo (ou lado com borda interna)
- Catodo: pino mais curto (ou lado com borda)
- Precisa de resistor para limitar corrente
- Sem resistor = queima

**O que é um resistor:**
- Limita corrente
- Cores indicam valor: vermelho-vermelho-marrom-dourado = 220Ω
- Potência: 1/4W (0.25W) é suficiente para LEDs

---

### Conceitos de Programação (se nunca programou)

**1. Variável:** algo que guarda um valor
```cpp
int x = 5;        // x guarda 5
bool ligado = true; // ligado guarda true
```

**2. Função:** bloco de código que faz algo
```cpp
void setup() {    // roda uma vez
  // configuração
}

void loop() {     // roda sempre
  // código principal
}
```

**3. Condicional:** escolha
```cpp
if (condição) {
  // faz algo
} else {
  // faz outra coisa
}
```

**4. Loop:** repetição
```cpp
for (int i = 0; i < 10; i++) {
  // repete 10 vezes
}
```

---

## ETAPA POR ETAPA

### E1: LED Estático (15 min)

**O que aprender:**
- Como montar circuito na protoboard
- Como usar resistor com LED
- Como medir com multímetro

**Material de estudo:**
- [[Componentes_Eletronicos_Completo]] — seções LED e Resistor
- Vídeo: "How to use a breadboard" no YouTube

**Checklist:**
- [ ] Entende o que é protoboard
- [ ] Sabe identificar anodo/catodo do LED
- [ ] Sabe calcular resistor com lei de Ohm
- [ ] Montou o circuito
- [ ] Mediu tensão com multímetro

**Dicas:**
- Teste o LED antes de montar (ligue direto na bateria com resistor)
- Se não acertar polaridade, o LED não acende (não queima)
- Multímetro no modo DC Voltage (V=)

---

### E2: Blink com ESP32 (30 min)

**O que aprender:**
- Como instalar Arduino IDE
- Como conectar ESP32
- Como enviar código
- O que é Serial Monitor

**Material de estudo:**
- [[Programacao_Para_Iniciantes]] — seção Arduino
- Site oficial: docs.espressif.com

**Checklist:**
- [ ] Arduino IDE instalado
- [ ] ESP32 conectado via USB
- [ ] Driver CH340 instalado (se necessário)
- [ ] Código carregou sem erro
- [ ] LED pisca a 1 Hz
- [ ] Serial Monitor mostra "Blink iniciado!"

**Dicas:**
- Se não achar a porta: instalar driver CH340
- Se não compilar: verificar se ESP32 selecionado em Tools → Board
- Pino 2 é o LED embutido no ESP32 DevKit

---

### E3: Botão com Pull-Down (30 min)

**O que aprender:**
- O que é pull-up e pull-down
- Por que o estado "flutua"
- Como ler sinais digitais

**Material de estudo:**
- [[01_Microcontroladores]] — seção GPIO e digitalRead

**Checklist:**
- [ ] Montou circuito com resistor 10kΩ
- [ ] LED liga quando botão pressionado
- [ ] LED desliga quando botão solto
- [ ] Entende o que é pull-down
- [ ] Removeu resistor e viu LED piscar (estado flutuante)

**Dica:** O pull-down mantém o pino em LOW quando o botão não está pressionado. Sem ele, o pino "flutua" entre HIGH e LOW.

---

### E4: Debounce (30 min)

**O que aprender:**
- O que é bounce mecânico
- Por que precisamos de debounce
- Como implementar em código

**Material de estudo:**
- [[01_Microcontroladores]] — seção debounce

**Checklist:**
- [ ] Observou bounce no Serial Monitor (múltiplas transições)
- [ ] Implementou debounce por tempo
- [ ] LED responde corretamente (1 pressão = 1 toggle)
- [ ] Entende que debounce = esperar estabilização mecânica

**Dica:** Use `INPUT_PULLUP` para não precisar de resistor externo.

---

### E5: PWM (30 min)

**O que aprender:**
- O que é PWM
- Relação duty cycle ↔ brilho
- Como usar analogWrite

**Material de estudo:**
- [[00_Eletronica_e_Eletronica]] — seção PWM

**Checklist:**
- [ ] LED faz fade in e fade out suave
- [ ] Entende que PWM = ON/OFF rápido = brilho médio
- [ ] Relacionou duty cycle com brilho (0-255 → 0-100%)
- [ ] Observou que LED não pisca (é lento demais para o olho)

**Dica:** O pino precisa suportar PWM. No ESP32, pinos com PWM estão marcados no pinout.

---

## RESUMO

| Etapa | Conceito Principal | Tempo |
|-------|-------------------|-------|
| E1 | Lei de Ohm, LED, resistor | 15 min |
| E2 | GPIO, digitalWrite, Serial | 30 min |
| E3 | Pull-down, estado flutuante | 30 min |
| E4 | Bounce, debounce | 30 min |
| E5 | PWM, duty cycle | 30 min |

**Tempo total: ~2.5 horas**

---

## Depois de P01

Quando terminar P01, você terá:
- ✅ Entendido eletrônica básica
- ✅ Montado circuitos na protoboard
- ✅ Programado ESP32 em C++
- ✅ Lido sinais digitais
- ✅ Implementado debounce
- ✅ Controlado PWM

**Próximo:** P02 — Rust Firmware (sensor → serial)
