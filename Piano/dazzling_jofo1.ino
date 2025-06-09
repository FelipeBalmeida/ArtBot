const int buttonPin1 = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;

const int ledPin1 = 8;
const int ledPin2 = 9;
const int ledPin3 = 10;

const int buzzerPin = 7;

const int noteC4 = 262;
const int noteD4 = 294;
const int noteE4 = 330;

int currentNote = 0;

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);

  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  Serial.begin(9600);
  Serial.println("Projetinho Piano Iniciado!");
}

void loop() {
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  int buttonState3 = digitalRead(buttonPin3);

  if (buttonState1 == LOW) {
    if (currentNote != noteC4) {
      tone(buzzerPin, noteC4);
      currentNote = noteC4;
    }
    digitalWrite(ledPin1, HIGH);
    Serial.println("Botao 1 pressionado - Nota C4");
  } else {
    if (currentNote == noteC4) {
      noTone(buzzerPin);
      currentNote = 0;
    }
    digitalWrite(ledPin1, LOW);
  }

  if (buttonState2 == LOW) {
    if (currentNote != noteD4) {
      tone(buzzerPin, noteD4);
      currentNote = noteD4;
    }
    digitalWrite(ledPin2, HIGH);
    Serial.println("Botao 2 pressionado - Nota D4");
  } else {
    if (currentNote == noteD4) {
      noTone(buzzerPin);
      currentNote = 0;
    }
    digitalWrite(ledPin2, LOW);
  }

  if (buttonState3 == LOW) {
    if (currentNote != noteE4) {
      tone(buzzerPin, noteE4);
      currentNote = noteE4;
    }
    digitalWrite(ledPin3, HIGH);
    Serial.println("Botao 3 pressionado - Nota E4");
  } else {
    if (currentNote == noteE4) {
      noTone(buzzerPin);
      currentNote = 0;
    }
    digitalWrite(ledPin3, LOW);
  }

  delay(10);
}
