# 🚀 Tarefas Trainees - Projetos com Arduino

---

## 📘 Tarefas

### 1. 🎹 Projetinho Piano
- **Componentes:** 3 Botões, 3 LEDs, 1 Buzzer.
- **Objetivo:** 
  - Cada botão toca uma nota musical diferente.
  - Cada botão também acende um LED correspondente.

---

### 2. 🚘 Sensor de Estacionamento
- **Componentes:** Sensor ultrassônico, Buzzer, LED RGB.
- **Objetivo:**
  - Desenvolver uma lógica com 4 estágios:
    1. **Muito longe:** LED verde aceso, buzzer desligado.
    2. **Perto:** LED verde piscando, buzzer desligado.
    3. **Mais perto:** LED vermelho piscando, buzzer tocando intermitente.
    4. **Muito perto:** LED vermelho estático, buzzer ligado direto.

---

### 3. 🎛️ Theremin Agudo
- **Componentes:** Sensor LDR (fotorresistor), LED, Buzzer.
- **Objetivo:**
  - Ler o valor do LDR e mostrar no monitor serial.
  - Usar `tone()` para gerar sons de 31 Hz a 2500 Hz, proporcional à leitura do LDR.
  - Variação do brilho do LED com `analogWrite()` baseado no valor do LDR.
  - Dicas:
    - Utilize `map()` para conversão do valor do LDR para frequências (0–1023 → 31–2500 Hz).
    - Use um segundo `map()` para conversão do brilho do LED (0–1023 → 0–255).

---

### 4. 🤖 Garra Robótica
- **Componentes:** 2 Potenciômetros, 3 Servos, 1 Botão.
- **Objetivo:**
  - Ler os dois potenciômetros, salvar os valores e exibir no monitor serial.
  - Controlar dois servos com `map()` e a biblioteca `<Servo.h>` para movimentação dos braços.
  - Utilizar um botão para **abrir e fechar a garra** usando uma função de **toggle**.

---

