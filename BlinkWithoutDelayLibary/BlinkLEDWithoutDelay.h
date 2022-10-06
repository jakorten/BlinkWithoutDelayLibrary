/*
  BlinkLEDWithoutDelay.h

  Blueprint of the BlinkLEDWithoutDelay library
  Based on the common Arduino example.

  Sept 14, 2022
  V0.1

  HAN University of Applied Sciences
  Embedded Systems Engineering

  Johan Korten
  johan.korten@han.nl
*/

#ifndef BLINK_LED_WITHOUT_DELAY
#define BLINK_LED_WITHOUT_DELAY

#include "Arduino.h"

class BlinkLEDWithoutDelay {
  private:
    int ledState = LOW;                   // ledState used to set the LED
    unsigned long previousMillis = 0;     // will store last time LED was updated
    const long _interval = 1000;          // interval at which to blink (milliseconds)
    const int _ledPin =  LED_BUILTIN;      // the number of the LED pin
  public:
    BlinkLEDWithoutDelay(const long interval = 1000, const int ledPin = LED_BUILTIN) : _interval(interval), _ledPin(ledPin) {}
    void checkBlinkLED();
    void toggleLED();
    bool checkIntervalExpired(unsigned long currentMillis, unsigned long previousMillis, long interval);
    unsigned long resetIntervalMillis();
    void toggleLEDState();
    void init();
};

#endif
