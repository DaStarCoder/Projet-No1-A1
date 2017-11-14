#include "Arduino.h"
#include "param.h"

void animerLed(int i) {

	if (i <= 13) {
		delay(100);
		if (i >= 0 && i <= 13) { digitalWrite(i, LOW); }
		if (i + NBLOUPIOTES >= 0 && i + NBLOUPIOTES <= 13) { digitalWrite((i + NBLOUPIOTES), HIGH); }
	}
}