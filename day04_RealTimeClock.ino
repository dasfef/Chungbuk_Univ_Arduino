#include <DS1302.h>
#define SCK_PIN 8
#define IO_PIN 7
#define RST_PIN 6

DS1302 rtc(RST_PIN, IO_PIN, SCK_PIN);
Time thisTime;
String DOW[] = {"SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY"};

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()){
    SetSerialTime();
  }
  else {
    thisTime = rtc.getTime();
    Serial.print("Now ");
  }
  SendSerialTime();
  delay(1000);
}

void SetSerialTime() {
  String Rxd;
  int LastPoint, FistPoint;

  Rxd = Serial.readStringUntil("\r\n");

  LastPoint = Rxd.indexOf('-');
  thisTime.year = Rxd.substring(0, LastPoint).toInt();
  FistPoint = LastPoint + 1;
  LastPoint = Rxd.indexOf('-', FistPoint);
  thisTime.mon = Rxd.substring(FistPoint, LastPoint).toInt();
  FistPoint = LastPoint + 1;
  LastPoint = Rxd.indexOf(' ', FistPoint);
  thisTime.date = Rxd.substring(FistPoint, LastPoint).toInt();

  FistPoint = LastPoint + 1;
  LastPoint = Rxd.indexOf(' ', FistPoint);
  thisTime.dow = DayOfWeekNo(Rxd.substring(FistPoint, LastPoint));

  FistPoint=LastPoint+1;
  LastPoint=Rxd.indexOf(':',FistPoint);
  thisTime.hour=Rxd.substring(FistPoint,LastPoint).toInt();
  FistPoint=LastPoint+1;
  LastPoint=Rxd.indexOf(':',FistPoint);
  thisTime.min=Rxd.substring(FistPoint,LastPoint).toInt();
  FistPoint=LastPoint+1;
  LastPoint=Rxd.indexOf(':',FistPoint);
  thisTime.sec=Rxd.substring(FistPoint,LastPoint).toInt();
  rtc.halt(false);
  rtc.writeProtect(false);
  rtc.setTime(thisTime.hour, thisTime.min, thisTime.sec);
  rtc.setDOW(thisTime.dow);
  rtc.setDate(thisTime.date, thisTime.mon, thisTime.year);
  rtc.writeProtect(true);
  Serial.println("----------------------------------");
  Serial.println("Set ");
}

void SendSerialTime( ){
  Serial.print(thisTime.year, DEC);
  Serial.print("-");
  Serial.print(thisTime.mon, DEC);
  Serial.print("-");
  Serial.print(thisTime.date, DEC);
  Serial.print(" ");
  Serial.print(DOW[thisTime.dow]);
  Serial.print(" ");
  Serial.print(thisTime.hour, DEC);
  Serial.print(":");
  Serial.print(thisTime.min, DEC);
  Serial.print(":");
  Serial.println(thisTime.sec, DEC);
}

int DayOfWeekNo(String strDow){
if (strDow.compareTo("SUNDAY")==0) return 7;
else if (strDow.compareTo("MONDAY")==0) return 1;
else if (strDow.compareTo("TUESDAY")==0) return 2;
else if (strDow.compareTo("WEDNESDAY")==0) return 3;
else if (strDow.compareTo("THURSDAY")==0) return 4;
else if (strDow.compareTo("FRIDAY")==0) return 5;
else if (strDow.compareTo("SATURDAY")==0) return 6;
else return 0;
}

// void setup() {
//   rtc.halt(false);
//   rtc.writeProtect(false);

//   rtc.setDOW(MONDAY);
//   rtc.setTime(16, 00, 00);
//   rtc.setDate(27, 3, 2023);
//   Serial.begin(9600);
// }

// void loop() {
//   thisTime = rtc.getTime();

//   Serial.print(thisTime.year, DEC);
//   Serial.print("-");
//   Serial.print(thisTime.mon, DEC);
//   Serial.print("-");
//   Serial.print(thisTime.date, DEC);
//   Serial.print(" ");

//   Serial.print(thisTime.hour, DEC);
//   Serial.print(":");
//   Serial.print(thisTime.min, DEC);
//   Serial.print(":");
//   Serial.println(thisTime.sec, DEC);

//   delay(1000);

  // Serial.print(rtc.getDOWStr());
  // Serial.print(" ");
  // Serial.print(rtc.getDateStr());
  // Serial.print(" -- ");
  // Serial.println(rtc.getTimeStr());

  // delay(1000);

// }
