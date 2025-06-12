/*
 * Scrolling text
 * @alifeee
 */

#include "Arduino.h"
#include <CH_AS1100.h>
#include <pins.h>

// panel length
#define NUM_CHIPS 32
Panel topRow = Panel(LOAD_PIN, NUM_CHIPS);
// Panel bottomRow = Panel(LOAD_PIN_2, NUM_CHIPS);

void showText(Panel &p, char *msg) {
  p.setCursor(0, 0);
  p.setTextColor(1);
  p.setTextSize(1); // pixel size multiplier
  p.println(msg);
  p.display();
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  topRow.begin();
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  topRow.displayTest(true);
  delay(1000);

  digitalWrite(LED_BUILTIN, HIGH);
  topRow.displayTest(false);
  delay(1000);
}
