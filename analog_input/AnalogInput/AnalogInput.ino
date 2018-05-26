#include "SEGGER_RTT.h"

int sensorPin;
int sensorValue;

char buffer[128];

unsigned long int t0 = millis();

int analogPins[] = {
  0, 1, 2, 3, 4, 5, 6, 30, 26, 27
};


void setup() {
  for (int i=0; i < sizeof(analogPins)/sizeof(int); i++) {
    pinMode(analogPins[i], INPUT);
  }
}

void loop() {
  unsigned long int t1 = millis();
  if (t1 - t0 > 10000) { 
    t0 = t1;
    for (int i=0; i < sizeof(analogPins)/sizeof(int); i++) {
      sensorPin = analogPins[i];
      sensorValue = analogRead(sensorPin);
      sprintf(buffer, "PIN %d: %d\n", sensorPin, sensorValue);
      SEGGER_RTT_WriteString(0, buffer);
    }
  }
}
