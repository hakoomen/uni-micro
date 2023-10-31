#include <Arduino.h>
#include <math.h>

int sevenSegmentNumberCodes[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0xfd, 0x07, 0x7f, 0x6f};

void countSevenSegment(int from, int to)
{
  for (int i = from; i <= to && i < sizeof(sevenSegmentNumberCodes) / sizeof(int); i++)
  {
    PORTC = sevenSegmentNumberCodes[i];
    _delay_ms(pow(10, 3));
  }
}

void setup()
{
  pinMode(PIN_PC0, OUTPUT);
  pinMode(PIN_PC1, OUTPUT);
  pinMode(PIN_PC2, OUTPUT);
  pinMode(PIN_PC3, OUTPUT);
  pinMode(PIN_PC4, OUTPUT);
  pinMode(PIN_PC5, OUTPUT);
  pinMode(PIN_PC6, OUTPUT);
  pinMode(PIN_PC7, OUTPUT);
}

void loop()
{
  countSevenSegment(0, 9);
}
