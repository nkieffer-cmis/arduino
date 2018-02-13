const byte led = 5;
const byte btn = 13;
boolean ledState = LOW;
boolean btnLast = LOW;
boolean btnState = LOW;
unsigned long fInterval = 1500;
unsigned long oInterval = 100;
unsigned long lastFlash = 0;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  unsigned long now = millis();
  boolean btnRead = digitalRead(btn);
  if (btnRead == HIGH && btnRead != btnLast) {
    btnState = !btnState;
  }
  btnLast = btnRead;
  //if (btnState == HIGH) {
    if (now - fInterval > lastFlash) {
      ledState = HIGH == btnState;
      lastFlash = now;
    }
    if (ledState == HIGH == btnState && now - oInterval > lastFlash) {
      ledState = LOW == btnState;
    }
  //}else{
    //ledState = HIGH;
  //}
  digitalWrite(led, ledState);
}
