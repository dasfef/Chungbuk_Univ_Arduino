int KeyRow[4] = {7, 6, 5, 4};
int KeyCol[4] = {8, 9, 10, 11};
int KeyValue = -1;
char KeyCode[16] = {'1', '2', '3', 'A',
                    '4', '5', '6', 'B',
                    '7', '8', '9', 'C',
                    '*', '0', '#', 'D'};

void setup() {
  Serial.begin(9600);
  for(int k = 0; k < 4; k++){
    pinMode(KeyRow[k], OUTPUT);
    digitalWrite(KeyRow[k], HIGH);
    pinMode(KeyCol[k], INPUT_PULLUP);
  }
}

void loop() {
  KeyValue = KeyScan();
  if (KeyValue >= 0){
    Serial.print("KEY=");
    Serial.print(KeyCode[KeyValue]);
    Serial.println(" Pressed");
  }
  delay(20);
}

int KeyScan() {
  int nRow, nNumber = -1;
  for(int k=0; k < 4; k++){
    digitalWrite(KeyRow[k], LOW);
    nRow = k*4;
    for(int m=0; m < 4; m++){
      if(!digitalRead(KeyCol[m])){
        nNumber = nRow + m;
      }}
    digitalWrite(KeyRow[k], HIGH);
  }
    return nNumber;
  
}
  
