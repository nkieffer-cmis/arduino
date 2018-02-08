const byte red = 10;
const byte yellow = 11;
const byte green = 12;
const byte ldr = A7;
boolean blinking = false;
boolean state = LOW;
unsigned long last = 0;
unsigned long duration = 500;
byte count = 0;
void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(ldr, INPUT);
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}

void loop() {
  int raw = analogRead(ldr);
  int level = map(raw, 350, 150, 0, 5);
  if (blinking == true) {
    unsigned long now = millis();
    if (now > (last + (duration/ ((state+1) * 2)))) {
      state = !state;
      last = now;
    }
    if (random(10000) == 9999) {
      blinking = false;
      state = LOW;
    }
    digitalWrite(red, state);
    digitalWrite(yellow, state);
    digitalWrite(green, state);
  } else {
    last = millis();
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(green, LOW);
    switch (level) {
      case 0:
        digitalWrite(green, HIGH);
        break;;
      case 1:
        digitalWrite(yellow, HIGH);
        break;;
      case 2:
        digitalWrite(red, HIGH);
        break;;
      case 3:
        blinking = true;
        break;
    }
  }
}

