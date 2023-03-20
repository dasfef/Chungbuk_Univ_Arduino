#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

long count = 0;

void setup(){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("IoT Smart SW");
  lcd.setCursor(2, 1);
  lcd.print("Count = ");
  Serial.begin(9600);
}

void loop() {
  lcd.setCursor(10, 1);
  lcd.print(count);

  // delay(500);
  if(++count > 999999) count = 0;
}