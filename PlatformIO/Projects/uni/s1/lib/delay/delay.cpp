#include "delay.h"
#include <Arduino.h>
#include <math.h>

void delaySeconds(int seconds)
{
    _delay_ms(seconds * pow(10, 3));
}

void delayMilliSeconds(int milliSeconds)
{
    _delay_ms(milliSeconds);
}

void delayMicroSeconds(int microSeconds)
{
    _delay_ms(microSeconds * pow(10, -3));
}