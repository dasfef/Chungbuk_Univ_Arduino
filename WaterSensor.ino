/*int resval = 0;
int respin = A5;

void setup() {
  Serial.begin(9600);
}

void loop() {
  resval = analogRead(respin);

  if(resval <= 100) Serial.println("Water Level : Empty");
  else if((resval > 100) && (resval <= 300)) Serial.println("Water Level : Low");
  else if((resval > 300) && (resval <= 330)) Serial.println("Water Level : Medium");
  else if(resval > 330) Serial.println("Water Level : High");
  delay(1000);
}*/

/*
#define WaterSensor A5

void setup() {
  Serial.begin(9600);
}

void loop() {
  int waterValue = analogRead(WaterSensor);
  Serial.println(waterValue);
  delay(100);
}*/

int water_pin = A5;
int RED = 2;
int YELLOW = 3;
int GREEN = 4;

void setup() {
  Serial.begin(9600);
  pinMode(water_pin, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop() {
  Serial.println(analogRead(water_pin));
  delay(100);
  if (analogRead(A5) < 550){
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);
    delay(100);
  }
  else if(550 < analogRead(water_pin) && analogRead(water_pin) < 650){
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);
    delay(100);
  }
  else if (650 < analogRead(water_pin) && analogRead(water_pin) < 660){
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(GREEN, LOW);
  }
  else {
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(GREEN, HIGH);
  }
}