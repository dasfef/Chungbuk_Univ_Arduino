#include <SimpleDHT.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);   // LiquidCrystal_I2C 변수설정(모델번호, 셀개수, 열개수)

// dht = 온도, 습도 센서
int DHT = 9;                      // 센서 9번핀에 연결 후 변수 지정
SimpleDHT11 dht11(DHT);           // dht11 객체 생성

byte temp = 0;
byte humi = 0;

void setup() {
  Serial.begin(9600);             // 보드레이트 설정
  lcd.init();                     // LiquidCrystal_I2C 초기화
  lcd.backlight();                // 백라이트 ON(default)
  lcd.setCursor(0, 0);            // 0번째 셀, 0번째 열에 커서 지정
  lcd.print("== DHT SENSOR ==");  // lcd에 프린트할 문구 설정
  lcd.setCursor(0, 1);            // 0번째 셀, 1번째 열에 커서 지정(두번째 줄 첫칸)
  lcd.print("...EXECUTING...");   // lcd에 프린트할 문구 설정

  delay(2000);
  lcd.clear();
}

void loop() {
  int err = dht11.read(&temp, &humi, NULL);   // dht11센서에서 받는 temp, humi 의 주소값 read
                                              // 값 = 0으로 반환된다
  if(err != SimpleDHTErrSuccess) {            // dht11 에서 에러가 발생한다면(read의 값이 0이 아니라면)
    lcd.setCursor(0, 0);
    lcd.print("dht11 Failed");
    lcd.setCursor(0, 1);
    lcd.print("error = " + err);
    delay(2000);
  }
  lcd.setCursor(0, 0);
  lcd.print("TEMP / HUMI");
  lcd.setCursor(0, 1);

  String(tempStr) = String(temp);             // 0xDF 섭씨온도의 표현을 위해 값을 문자열로 변경
  String(humiStr) = String(humi);

  lcd.print(tempStr + (char)0xDF + "C ");   // 0xDF : 섭씨온도 표시
  lcd.print(humiStr + "H");
  // lcd.clear();

  Serial.print("Sample OK : ");
  Serial.print((int)temp); Serial.print(" C ");
  Serial.print((int)humi); Serial.println(" H");
  delay(2000);
}