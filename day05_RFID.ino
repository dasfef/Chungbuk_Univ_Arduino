#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);
int GREEN = 3;
int RED = 4;
int buzzer = 6;

byte SetID[4] = {0x83, 0x0F, 0x96, 0xA9};

void setup() {
  Serial.begin(9600);
  SPI.begin();

  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  mfrc522.PCD_Init();
  mfrc522.PCD_DumpVersionToSerial();
  Serial.println("MFRC522 Ready");
}

void loop() {
  if(!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) { delay(500); return;}
  if(mfrc522.uid.uidByte[0] == SetID[0] && mfrc522.uid.uidByte[1] == SetID[1] && mfrc522.uid.uidByte[2] == SetID[2] &&
  mfrc522.uid.uidByte[3] == SetID[3]) {
    digitalWrite(GREEN, HIGH);
    digitalWrite(RED, LOW);
    Serial.println("Hello Welcome :D");
    tone(6, 523, 100);
    delay(500);
  }

  else{
    digitalWrite(RED, HIGH);
    digitalWrite(GREEN, LOW);
    Serial.println("Who are you?");
    tone(6, 2023, 1500);
    // delay(10);
    tone(6, 2023, 1500);
    delay(20);
  }

}
