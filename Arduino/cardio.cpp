#include "cardio.h"
#include "Arduino.h"
/*unsigned int i;
void setup(){
  
}
void loop(){
  
}*/
static long battprec = 0;
static int delai = 900;

int a0() {
 return analogRead(0);
}

int rng() {
    if (battprec < millis()-delai) {
    battprec = millis();
    delai += 10 - (rand() % 21);

    if (delai > 1200) {delai = 1200;}
    if (delai < 500) {delai = 500;}

    return 900;
  } else {
    if (battprec > millis()-100) {
      return 900;
    }
    return 200;
  }
}
  
int obtenirSignal() {
  return a0();
}

/*void bidule() {
  delay(100);
  digitalWrite(i % 14      ,LOW);
  digitalWrite((i + 1) % 14,HIGH);
  i++;
}*/

