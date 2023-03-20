#define LM35 A0
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" Temp Monitor ");

  delay(3000);
  lcd.clear();
}

void loop() {
  int ADCValue = analogRead(LM35);
  Serial.println(ADCValue);
  String(ADCstr) = String(ADCValue);

  lcd.setCursor(0, 0);
  lcd.print("ADC = " + ADCstr);

  float TempValue = ((ADCValue * 5.0 * 100.0) / 1024.0);
  String(Tempstr) = String(TempValue);
  lcd.setCursor(0, 1);
  lcd.print("Temp is " + Tempstr + (char)0xDF + "C");

  delay(2000);
  lcd.clear();
}