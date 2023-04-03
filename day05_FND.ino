int digitPin[ ] = { 10, 11, 12, 13 };
int digits=4;
int segmentPin[ ] = { 7, 9, 3, 5, 6, 8, 2, 4 };
int segments = 8;
int Digit[10][8] = {
{1, 1, 1, 1, 1, 1, 0, 0}, //0
{0, 1, 1, 0, 0, 0, 0, 0}, //1
{1, 1, 0, 1, 1, 0, 1, 0}, //2
{1, 1, 1, 1, 0, 0, 1, 0}, //3
{0, 1, 1, 0, 0, 1, 1, 0}, //4
{1, 0, 1, 1, 0, 1, 1, 0}, //5
{1, 0, 1, 1, 1, 1, 1, 0}, //6
{1, 1, 1, 0, 0, 0, 0, 0}, //7
{1, 1, 1, 1, 1, 1, 1, 0}, //8
{1, 1, 1, 1, 0, 1, 1, 0}}; //9};
char FND[4];
int Count=0;

void setup( ) {
  for (int k = 0 ; k < digits ; k++) {
  pinMode(digitPin[k], OUTPUT);
  digitalWrite(digitPin[k], HIGH);
  }
  for (int k = 0 ; k < segments ; k++) {
  pinMode(segmentPin[k], OUTPUT);
  }
}

void loop( ) {
  Hex2Dec( );
  for (int m = 0 ; m < digits ; m++) {
    digitalWrite(digitPin[m], LOW);
  for (int k = 0 ; k < segments ; k++) {
    digitalWrite(segmentPin[k], Digit[ FND[m] ] [k]);
  }
  delay(4);
  digitalWrite(!digitPin[m], HIGH);
  }
  if (++Count>9999) Count=0;
  }

void Hex2Dec( ){
  int temp=Count;
  FND[1]=temp/1000;
  temp %=1000;
  FND[2]=temp/100;
  temp %=100;
  FND[3]=temp/10;
  temp %=10;
  FND[4]=temp;
}