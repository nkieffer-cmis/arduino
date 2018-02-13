const byte led = 5;
const byte btn = 13;
unsigned long last = 0;
unsigned long wait = 100;
int count = 0;
boolean btnState = 0;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  unsigned long now = millis();
  if (now - wait > last) {
    int btnRead = digitalRead(btn);
    if ( btnRead != btnState && btnRead == true){
      count++;
    }
    btnState = btnRead;
  }
  Serial.println(count);
  digitalWrite(led, btnState);

}
