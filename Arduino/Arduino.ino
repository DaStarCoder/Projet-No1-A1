//include "cardio.h"
#include "param.h"
#include "coeur.h"


int i;


void setup() {
  Serial.begin(9600);
  for (i = 0; i <= 13; i++) // Initialisation de tous les pins (0 à 13)
    {pinMode(i,OUTPUT);}
  i = 0;
}


void loop() {
  if (analogRead(0) > 500) { i = -1 * NBLOUPIOTES; }
  animerLed(i);
  if (i < 14) {
    Serial.print(i);
    Serial.print('\n');
  }
  i++;
}

