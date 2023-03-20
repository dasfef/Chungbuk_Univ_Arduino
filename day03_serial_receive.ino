unsigned char LED[8] = {9, 8, 7, 6, 5, 4, 3, 2};
unsigned char Mask[8] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
unsigned char LED_Buff = 0x00;

void setup() {
  for (int k = 0; k < 8; k++)pinMode(LED[k], OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()) {
    unsigned char inByte = Serial.parseInt();
    if(inByte > 7) {
      Serial.print(inByte);
      Serial.println(" LED Failed");
    }
    
    else {
      LED_Buff = 1 << inByte;
      
      for(int k = 0; k < 8; k++)
        digitalWrite(LED[k], LED_Buff & Mask[k]);
      Serial.print(inByte);
      Serial.println(" LED OK!");
    }
  }
}