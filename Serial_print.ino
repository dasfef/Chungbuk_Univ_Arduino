const unsigned char temp[5] = {'1', '2', '3', '4', '5'};
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.write(1);
  Serial.print(1);
  Serial.write(65);

  Serial.write(0x65);
  Serial.write('a');

  Serial.write(temp, 4);
  Serial.write("12345");

  Serial.write('\n');
  delay(500);
}