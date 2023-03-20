int Tilt_Pin = 3;
int LED_Pin = 7;

void setup() {
  pinMode(Tilt_Pin, INPUT_PULLUP);
  pinMode(LED_Pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int TiltState = digitalRead(Tilt_Pin);
  Serial.println(TiltState);

  if(TiltState==HIGH) {
    digitalWrite(LED_Pin, HIGH);
  }
  else{
    digitalWrite(LED_Pin, LOW);
  }
  delay(300);
}