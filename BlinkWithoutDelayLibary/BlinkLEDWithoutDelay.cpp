/*
  BlinkLEDWithoutDelay.cpp

  Implementation of the BlinkLEDWithoutDelay library
  Based on the common Arduino example.

  Sept 14, 2022
  V0.1

  HAN University of Applied Sciences
  Embedded Systems Engineering

  Johan Korten
  johan.korten@han.nl
*/

#include "BlinkLEDWithoutDelay.h"

void BlinkLEDWithoutDelay::checkBlinkLED() {
  // here is where you'd put code that needs to be running all the time.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.

  if (checkIntervalExpired(millis(), previousMillis, _interval)) {
    resetIntervalMillis();
    toggleLEDState();
    toggleLED();
  }
}

void BlinkLEDWithoutDelay::toggleLEDState() {
  // if the LED is off turn it on and vice-versa:
  ledState = !ledState;
}

void BlinkLEDWithoutDelay::init() {
  pinMode(_ledPin, OUTPUT);
}

void BlinkLEDWithoutDelay::toggleLED() {
  // set the LED with the ledState of the variable:
  digitalWrite(_ledPin, ledState);
}

unsigned long BlinkLEDWithoutDelay::resetIntervalMillis() {
  previousMillis = millis();
}

bool BlinkLEDWithoutDelay::checkIntervalExpired(unsigned long currentMillis, unsigned long previousMillis, long interval) {
  return (currentMillis - previousMillis >= interval);
}
