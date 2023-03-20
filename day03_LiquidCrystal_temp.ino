#include <SimpleDHT.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int DHT_pin = 9;
SimpleDHT11 dht11(DHT_pin);

byte temp = 0;
byte humi = 0;

void setup() {
  lcd.init();
  lcd.backlight();
  
  Serial.begin(9600);
}

void loop() {
  int err = dht11.read(&temp, &humi, NULL);

  if (err != SimpleDHTErrSuccess) {
    lcd.print("Read DHT11 Failed, err = ");
    lcd.println(err);
    delay(1000);
    return;
  }
  lcd.setCursor(2, 0);
  lcd.print("Sample OK:   ");
  lcd.setCursor(2, 1);
  lcd.print((int)temp); lcd.print(" *C, ");
  lcd.print((int)humi); lcd.print(" H ");

  Serial.print((int)temp); Serial.print(",");
  Serial.println((int)humi);

  delay(3000);

  lcd.setCursor(2, 0);
  lcd.print("IoT Smart SW");
  lcd.setCursor(2, 1);
  lcd.print("Yeon-Woong  ");

  delay(3000);
}
