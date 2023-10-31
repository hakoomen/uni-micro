#include <Arduino.h>
#include "delay.h"

void setup()
{
  pinMode(PIN_PC0, OUTPUT);
}

void loop()
{
  delaySeconds(1);
  digitalWrite(PIN_PC0, HIGH);
  delaySeconds(1);
  digitalWrite(PIN_PC0, LOW);
}