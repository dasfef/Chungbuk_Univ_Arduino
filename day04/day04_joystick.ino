#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define Yaxis A0
#define Xaxis A1
#define Button A2
#define soundBtn 7

int xValue, yValue, btn;
int melody[] = {2637, 2794, 3136, 2637, 2794, 3136, 2637, 2794, 3136, 3520};
int i;
void setup() {
  lcd.init();

  pinMode(soundBtn, OUTPUT);
  Serial.begin(9600);
  pinMode(Button, INPUT_PULLUP);
  lcd.backlight();
}

void loop() {
  lcd.backlight();

  xValue = analogRead(Xaxis);
  xValue = map(xValue, 0, 1023, -100, 100);
  yValue = analogRead(Yaxis);
  yValue = map(yValue, 0, 1023, -100, 100);
  btn = digitalRead(Button);

  lcd.init();
  lcd.setCursor(0, 0);
  lcd.print("X:");
  lcd.print(xValue);
  lcd.setCursor(0, 1);
  lcd.print("Y:");
  lcd.print(yValue);

  int x = xValue / 22 + 11;
  int y = yValue / 22 + 11;
  lcd.setCursor(x, 0);
  lcd.write(0x7C);
  lcd.setCursor(y, 1);
  lcd.write(0x7c);

  if(btn == LOW) {
    for(i = 0; i < 10; i++){
      tone(soundBtn, melody[i], 500);
    }
    
    // delay(100);
    // lcd.noBacklight();
    // delay(100);
    // lcd.backlight();
    // delay(100);

  }

  else {
    digitalWrite(soundBtn, LOW);
  }
  delay(10);
  // lcd.clear();

}





// int xValue, yValue, btn;

// void setup() {
//   Serial.begin(9600);
//   pinMode(Button, INPUT_PULLUP);
// }

// void loop(){
//   xValue = analogRead(Xaxis);
//   xValue = map(xValue, 0, 1023, -100, 100);
//   yValue = analogRead(Yaxis);
//   yValue = map(yValue, 0, 1023, -100, 100);

//   btn = digitalRead(Button);

//   // Serial.print("X Value = ");
//   Serial.print(xValue);
//   Serial.print(",");
//   // Serial.print(" Y Value = ");
//   Serial.print(yValue);
//   Serial.print(",");
//   // Serial.print("BT = ");
//   Serial.println(btn);
// }

