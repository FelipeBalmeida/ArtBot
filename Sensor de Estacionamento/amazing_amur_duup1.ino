const int trigPin = 5;
const int echoPin = 6;
const int buzzerPin = 7;
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

const int DISTANCIA_MUITO_LONGE = 200;
const int DISTANCIA_PERTO = 100;
const int DISTANCIA_MAIS_PERTO = 20;

unsigned long previousMillisBlinkGreen = 0;
const long intervalBlinkGreen = 500;

unsigned long previousMillisBlinkRed = 0;
const long intervalBlinkRed = 250;

unsigned long previousMillisBuzzer = 0;
const long intervalBuzzerOn = 100;
const long intervalBuzzerOff = 150;

const int BUZZER_FREQ_INTERMITENTE = 1000;
const int BUZZER_FREQ_CONTINUO = 1500;

bool greenLedState = LOW;
bool redLedState = LOW;
bool buzzerSoundOn = false;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzerPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(9600);
  Serial.println("Sensor de Estacionamento Iniciado!");
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  float distanceCm = duration / 58.0;

  Serial.print("Distancia: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  unsigned long currentMillis = millis();

  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);
  noTone(buzzerPin);
  buzzerSoundOn = false;

  if (distanceCm > DISTANCIA_MUITO_LONGE || distanceCm == 0) {
    digitalWrite(greenPin, HIGH);
    Serial.println("Estagio: Muito Longe");
  } else if (distanceCm > DISTANCIA_PERTO) {
    if (currentMillis - previousMillisBlinkGreen >= intervalBlinkGreen) {
      previousMillisBlinkGreen = currentMillis;
      greenLedState = !greenLedState;
      digitalWrite(greenPin, greenLedState);
    }
    Serial.println("Estagio: Perto");
  } else if (distanceCm > DISTANCIA_MAIS_PERTO) {
    if (currentMillis - previousMillisBlinkRed >= intervalBlinkRed) {
      previousMillisBlinkRed = currentMillis;
      redLedState = !redLedState;
      digitalWrite(redPin, redLedState);
    }

    if (buzzerSoundOn) {
      if (currentMillis - previousMillisBuzzer >= intervalBuzzerOn) {
        noTone(buzzerPin);
        buzzerSoundOn = false;
        previousMillisBuzzer = currentMillis;
      }
    } else {
      if (currentMillis - previousMillisBuzzer >= intervalBuzzerOff) {
        tone(buzzerPin, BUZZER_FREQ_INTERMITENTE);
        buzzerSoundOn = true;
        previousMillisBuzzer = currentMillis;
      }
    }
    Serial.println("Estagio: Mais Perto");
  } else {
    digitalWrite(redPin, HIGH);
    tone(buzzerPin, BUZZER_FREQ_CONTINUO);
    Serial.println("Estagio: Muito Perto");
  }
}
