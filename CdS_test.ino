#define CdS A0
int adValue;
int lightValue;

void setup() {
  Serial.begin(9600);
}

void loop() {
  adValue = analogRead(CdS);
  lightValue = map(adValue, 0, 1023, 100, 0);

  Serial.print("CdS = ");
  Serial.print(adValue );
  Serial.print(" / Light % = ");
  Serial.println(lightValue);
  delay(200);
}