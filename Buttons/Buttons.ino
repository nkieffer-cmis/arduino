const byte led = 5;
const byte btn = 13;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int btnState = digitalRead(btn);
  Serial.println(btnState);
  digitalWrite(led, btnState);

}
