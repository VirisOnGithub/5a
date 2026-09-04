#include "rom/ets_sys.h"

hw_timer_t* timer = NULL;

bool currentState = false;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelayMs = 50;

void IRAM_ATTR timerIsr() {
  currentState = !currentState;
}

void IRAM_ATTR buttonIsr() {
  if ((millis() - lastDebounceTime) > debounceDelayMs) {
    currentState = !currentState;
  }
  lastDebounceTime = millis();
}

void setup() {
  Serial.begin(115200);
  timer = timerBegin(1000000);  // timer freq = 1MHz
  timerAttachInterrupt(timer, &timerIsr);
  timerAlarm(timer, 5000000, true, 0);  // 1 000 000 ticks ~1 sec

  pinMode(A0, OUTPUT);
  pinMode(A2, INPUT);

  attachInterrupt(A2, buttonIsr, RISING);
}
void loop() {
  digitalWrite(A0, currentState ? HIGH : LOW);
}