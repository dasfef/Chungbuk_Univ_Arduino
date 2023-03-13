int randNumber;

void setup(){
  Serial.begin(9600);
  randomSeed(analogRead(5));
}

void loop() {
  randNumber = random(300);
  Serial.println(randNumber);

  delay(50);
}