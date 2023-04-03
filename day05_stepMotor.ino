#include <Stepper.h>
const int stepsPerRevolution = 2048;
Stepper step28BYJ48(stepsPerRevolution, 8,10,9,11);
float stepPerAngle=2048.0/360.0;
#define programCount 6
int programData[programCount]={90,45,270,90,180,0};
int programPoint=0;
int currentAngle=0;
signed int steps;
void setup( ) {
step28BYJ48.setSpeed(15);
Serial.begin(9600);
}

void loop( ) {
steps=(int)(programData[programPoint]-currentAngle)*stepPerAngle;
step28BYJ48.step(steps);
currentAngle=programData[programPoint];
if (++programPoint>=programCount)
programPoint=0;
delay(1000);
}