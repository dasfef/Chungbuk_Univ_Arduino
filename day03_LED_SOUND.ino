const byte button_pin = 3;
const byte ledPin = 7;
const byte SoundPin = 8;
volatile byte state = LOW;

void setup() {
  pinMode(button_pin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(SoundPin, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(button_pin), inter_func, RISING);
}

void loop() {
  digitalWrite(ledPin, state);
  digitalWrite(SoundPin, state);
  Serial.println(state);
}

void inter_func() {
  state =! state;
}