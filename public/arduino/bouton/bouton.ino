#include "FeatherShieldPinouts.h"

bool lightOn = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, OUTPUT);
  pinMode(A2, INPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int read = digitalRead(A2);
  if (read == 1) {
    digitalWrite(A0, lightOn ? LOW : HIGH);
    lightOn = !lightOn;
    delay(500);
  }
}
