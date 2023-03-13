// #define FlameSensor A0
// #define LED 8
// void setup() {
//   Serial.begin(9600);
// }

// void loop() {
//   int FlameValue = analogRead(FlameSensor);
//   Serial.println(FlameValue);
//   digitalWrite(LED, LOW);
//   if (FlameValue > 500){
//     digitalWrite(LED, HIGH);
//   }
// }

const int sensorMin = 0;
const int sensorMax = 1023;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorReading = analogRead(A0);
  int range = map(sensorReading, sensorMin, sensorMax, 3, 0);
  Serial.println(sensorReading);
switch(range){
  case 0:
    Serial.println("** Close Fire **");
    break;

  case 1:
    Serial.println("** Distant Fire **");
    break;

  case 2:
    Serial.println("No Fire");
    break;


}
delay(1);
}