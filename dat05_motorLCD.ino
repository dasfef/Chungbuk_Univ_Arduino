#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define ServoPin 3
Servo servo;
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define VolumePin A0

int Angle = 0;

void setup(){
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  servo.attach(ServoPin);
  lcd.setCursor(1, 0);
  lcd.print("Servo Motor");
}

void loop(){
  int Volume = analogRead(VolumePin);
  Angle = map(Volume, 0, 1023, 0, 180);
  servo.write(Angle);
  delay(15);

  Display(Angle);
}

void Display(int Angle) {
  Serial.print("Angle = ");
  Serial.println(Angle);

  lcd.setCursor(2, 0);
  lcd.print("Servo Motor");
  lcd.setCursor(4, 1);
  lcd.print("Angle = ");
  lcd.print(String(Angle) + char(0xdf));
  delay(200);
  lcd.clear();
}