#include "param.h"
#include "coeur.h"
#include "cardio.h"


static long battementPrec = 0;
static long envoiPrec = 0;
static double frequence = 0;
static int enBattement = 0;

void setup() {
  Serial.begin(9600);
  initLed();
}


void loop() {
  int li = 0;
  if (enBattement) { li = -1 * NBLOUPIOTES; }
  if (animerLed(li)) { li++; }
//  if (i < 14 && 0) {
//    Serial.print(i);
//    Serial.print('\n');
//  }

    if (obtenirSignal() > 500) {
      if (!enBattement) {
        if (battementPrec != 0) {
          frequence = 1000./(millis() - battementPrec)*60;
        }
        battementPrec = millis();
      enBattement = 1;
      }
    } else {
      enBattement = 0;
    }
    if (enBattement) {
      digitalWrite(13,HIGH);
    } else {
      digitalWrite(13,LOW);
    }
    if (millis() - envoiPrec > INTERVALLEENVOI) {
      Serial.print(millis());
      Serial.print(';');
      Serial.println(frequence);
      envoiPrec = millis();
    }
}

