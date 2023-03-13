void setup(){
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int readValue = analogRead(A0);
  Serial.println(readValue);

  if(readValue > 400){
    digitalWrite(8, HIGH);
  }
  else{
    digitalWrite(8, LOW);
  }
}