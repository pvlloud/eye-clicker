#include <Arduino.h>
#include "OneButton.h"
#include "pinConfig.h"

OneButton buttonEmpty(BUTTON_EMPTY, true);
OneButton buttonRed(BUTTON_RED, true);
OneButton buttonWhite(BUTTON_WHITE, true);

void initiateAll() {
    for (int i=1; i<=9; i++){
      pinMode(i, OUTPUT);
    }
    pinMode(13, OUTPUT);
}

void setAllLow() {
    for (int i=1; i<=9; i++){
      digitalWrite(i, LOW);
    }
    digitalWrite(13, LOW);
}

void lightsOff() {
    digitalWrite(PIN_BLUE, HIGH);
    digitalWrite(PIN_GREEN, HIGH);
    digitalWrite(PIN_RED, HIGH);
}

void lightWhitish() {
    lightsOff();
    digitalWrite(PIN_BLUE, LOW);
    digitalWrite(PIN_GREEN, LOW);
}

void lightRed() {
    lightsOff();
    digitalWrite(PIN_RED, LOW);
}

void setup() {
    initiateAll();
    setAllLow();
    lightsOff();
    buttonEmpty.attachClick(lightsOff);
    buttonRed.attachClick(lightRed);
    buttonWhite.attachClick(lightWhitish);
}

void loop() {
    buttonEmpty.tick();
    buttonRed.tick();
    buttonWhite.tick();
}
