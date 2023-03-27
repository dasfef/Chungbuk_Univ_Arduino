// #define PIEZO 8
// int do1 = 2093;
// int re = 2349;
// int mi = 2637;
// int fa = 2793;
// int sol = 3136;
// int ra = 3520;
// int si = 3951;
// int do2 = 4186;
// int song[] = {do1, re, mi, re, mi, re, mi, re, mi, fa, fa, mi, re, fa, mi, fa, sol, mi, sol, mi, sol};

// void setup() {

// }

// void loop() {
//   for (int k = 0; k < 20; k++) {
//     tone(PIEZO, song[k], 500);
//     delay(500);
//   }
// }
// #include "pitches.h";
// #define PIEZO 8

/* 징글벨 */
// int melody[ ] = {
//   NOTE_G4, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_G4, 0, // 솔미레도솔 ()
//   NOTE_G4, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_A4, 0, // 솔미레도라 ()
//   NOTE_A4, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_B4, 0, // 라파미레시 ()
//   NOTE_G5, NOTE_G5, NOTE_F5, NOTE_D5, NOTE_E5, NOTE_C5, 0 
//   }; // 솔솔파레미도 ()
// 징글벨 첫 소절 연주시간 // 8분음표 = 250ms
// int tempo[ ] = { 250, 250, 250, 250, 750, 250,
//   250, 250, 250, 250, 750, 250,
//   250, 250, 250, 250, 750, 250,
//   250, 250, 250, 250, 500, 250, 250 };

// void setup( ) {
//   pinMode(PIEZO, OUTPUT);
// }
// void loop( ) {
//   for (int k=0; k<25; k++) {
//   tone(PIEZO, melody[k], tempo[k]);
//   delay(tempo[k]);
//   }
// }
#include "pitches.h";
#define PIEZO 8

/* 도레미송 */
// int melody [] = {
//   NOTE_C4, NOTE_D4, NOTE_E4, NOTE_C4, NOTE_E4, NOTE_C4, NOTE_E4,
//   NOTE_D4, NOTE_E4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_D4, NOTE_F4,
//   NOTE_E4, NOTE_F4, NOTE_G4, NOTE_E4, NOTE_G4, NOTE_E4, NOTE_G4,
//   NOTE_F4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_F4, NOTE_A4,
//   NOTE_G4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4,
//   NOTE_A4, NOTE_D4, NOTE_E4, NOTE_FS4, NOTE_G4, NOTE_A4, NOTE_B4,
//   NOTE_B4, NOTE_E4, NOTE_FS4, NOTE_GS4, NOTE_A4, NOTE_B4, NOTE_C5,
//   NOTE_C5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_F4, NOTE_B4, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_E4, NOTE_D4,
//   NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_G4, NOTE_C5
// };

// int tempo[] = {750, 250, 750, 250, 500, 500, 1000, 750, 250, 250, 250, 250, 250, 1000,
//   750, 250, 750, 250, 500, 500, 1000, 750, 250, 250, 250, 250, 250, 1000, 750, 250, 250, 250, 250, 250, 1000,
//   750, 250, 250, 250, 250, 250, 1000, 750, 250, 250, 250, 250, 250, 1000, 250, 250,
//   500, 500, 500, 500, 500, 500, 500, 500, 250, 250, 250, 250, 250, 250, 250, 500, 500, 1000};

/* 엘리제를 위하여 */
int melody[] = {  NOTE_E4, NOTE_DS4, NOTE_E4, NOTE_DS4, NOTE_E4, NOTE_B3, NOTE_D4, NOTE_C4, NOTE_A3,0,
  NOTE_C3, NOTE_E3, NOTE_A3, NOTE_B3, 0, NOTE_E3, NOTE_GS3, NOTE_B3, NOTE_C4, 0,
  NOTE_E3, NOTE_E4, NOTE_DS4, NOTE_E4, NOTE_DS4, NOTE_E4, NOTE_B3, NOTE_D4, NOTE_C4, NOTE_A3, 0,
  NOTE_C3, NOTE_E3, NOTE_A3, NOTE_B3, 0, NOTE_E3, NOTE_C4, NOTE_B3, NOTE_A3};

int tempo[] = {250, 250, 250, 250, 250, 250, 250, 250, 250, 250,
  250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250,
  250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 500};

void setup( ) {
  pinMode(PIEZO, OUTPUT);
}
void loop( ) {
  for (int k=0; k<40; k++) {
  tone(PIEZO, melody[k], tempo[k]);
  delay(tempo[k]);
  }
}