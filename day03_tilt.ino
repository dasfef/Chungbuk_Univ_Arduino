#define Tilt 3
int TiltState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(Tilt, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(Tilt), Tilt_ISR, RISING);
}

void loop() {
  if(TiltState) {
    Serial.println("Tilt On");
    TiltState = 0;
  }
  else {
    Serial.println("Tilt Off");
  }
  delay(300);
}

void Tilt_ISR() {
  TiltState = 1;
}

