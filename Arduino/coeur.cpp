#include "Arduino.h"
#include "param.h"
#include "coeur.h"

static long delai = 0;

int delayer(int d) {
  if (millis() >= delai + d) {
    delai = millis();
    return 1;
  } else {return 0;}
}

void initLed() {
  int i;
    for (i = 0; i <= 13; i++) // Initialisation de tous les pins (0 à 13)
    {pinMode(i,OUTPUT);}
  i = 0;
}
int animerLed(int li) {

	if (li <= 13) {
		if (delayer(100)) {
		  if (li >= 0 && li <= 13) { digitalWrite(li, LOW); }
		  if (li + NBLOUPIOTES >= 0 && li + NBLOUPIOTES <= 13) { digitalWrite((li + NBLOUPIOTES), HIGH); }
     return 1;
		}
	}
 return 0;
}
