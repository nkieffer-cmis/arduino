const byte led = 5;
const byte btn = 13;
boolean btnState = LOW;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  boolean btnRead = digitalRead(btn);
  if(btnRead == HIGH){
    btnState = !btnState;
  }
  digitalWrite(led, btnState);
}
