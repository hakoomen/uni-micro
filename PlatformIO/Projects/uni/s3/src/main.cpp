#include <Arduino.h>
#include <math.h>

const int sevenSegmentNumberCodes[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0xfd, 0x07, 0x7f, 0x6f};

uint8_t rotateRight(uint8_t value)
{
  return (value >> 1) | (value << 7);
}

uint8_t rotateLeft(uint8_t value)
{
  return (value << 1) | (value >> 7);
}

short getNumberLength(int number)
{
  int numberLength = 0;
  do
  {
    numberLength += 1;
  } while ((int)(number / pow(10, numberLength)) > 0);
  return numberLength;
}

// 1-indexed
// for instance 8123 -> 3 = 1st digit
// for instance 8123 -> 8 = 4st digit
char getDigitAt(int number, int digit)
{
  int i = 0;
  int remainder = number;
  int quotient = 0;
  for (i = getNumberLength(number); i >= digit; i--)
  {
    quotient = floor(remainder / ceil(pow(10, i - 1)));
    remainder = floor(remainder % (int)ceil(pow(10, i - 1)));
  }
  return quotient;
}

void showNumber(int number)
{
  PORTD = 0xfe;
  for (int i = getNumberLength(number); i > 0; i--)
  {
    PORTC = sevenSegmentNumberCodes[getDigitAt(number, i)];
    _delay_ms(pow(10, 3));
    PORTD = rotateLeft(PORTD);
    PORTC = 0;
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

  pinMode(PIN_PD0, OUTPUT);
  pinMode(PIN_PD1, OUTPUT);
  pinMode(PIN_PD2, OUTPUT);
  pinMode(PIN_PD3, OUTPUT);
  pinMode(PIN_PD4, OUTPUT);
  pinMode(PIN_PD5, OUTPUT);
  pinMode(PIN_PD6, OUTPUT);
  pinMode(PIN_PD7, OUTPUT);
}

void loop()
{
  showNumber(1234);
}
