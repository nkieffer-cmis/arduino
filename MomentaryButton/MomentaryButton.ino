const byte led = 5;
const byte btn = 13;
int count = 0;
int oldState = 0;
void setup() {
  pinMode(led, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int btnState = digitalRead(btn);
  if(btnState == HIGH && oldState != btnState){
    count++;
  }
  oldState = btnState;
  Serial.println(count);
  digitalWrite(led, btnState);

}
