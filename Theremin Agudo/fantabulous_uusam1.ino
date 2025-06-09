// Definição dos pinos
const int ldrPin = A0;
const int ledPin = 9;
const int buzzerPin = 8;

// Limites para som e brilho
const int MIN_FREQ = 31;
const int MAX_FREQ = 2500;
const int MIN_BRIGHTNESS = 0;
const int MAX_BRIGHTNESS = 255;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin);
  Serial.print("Leitura do LDR: ");
  Serial.println(ldrValue);

  // Mapeia LDR para frequência
  int frequency = map(ldrValue, 0, 1023, MIN_FREQ, MAX_FREQ);
  frequency = constrain(frequency, MIN_FREQ, MAX_FREQ);
  tone(buzzerPin, frequency);

  // Mapeia LDR para brilho do LED
  int brightness = map(ldrValue, 0, 1023, MIN_BRIGHTNESS, MAX_BRIGHTNESS);
  brightness = constrain(brightness, MIN_BRIGHTNESS, MAX_BRIGHTNESS);
  analogWrite(ledPin, brightness);

  delay(50);
}
