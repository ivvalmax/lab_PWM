#include "../inc/sevenSegment.h"

const uint8_t segments[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D,0x7D, 0x07, 0x7F, 0x6F, 0x40};

void sevenSegmentInit(void)
{
  DDRA |= (1 << PA1) | (1<<PA2) | (1 << PA3) | (1 << PA4) | (1 << PA5);
  DDRC |= (1 << PC0) | (1 << PC1) | (1 << PC2) | (1 << PC3) | (1 << PC4) | (1 << PC5) | (1 << PC6);  
}

void sevenSegmentClear(void)
{
  PORTA |= (1 << PA1) | (1<<PA2) | (1 << PA3) | (1 << PA4) | (1 << PA5);
  PORTC &= ~((1 << PC0) | (1 << PC1) | (1 << PC2) | (1 << PC3) | (1 << PC4) | (1 << PC5) | (1 << PC6));
  PORTA &= ~((1 << PA1) | (1<<PA2) | (1 << PA3) | (1 << PA4) | (1 << PA5));
}

void sevenSegmentWrite(Encoder_t *encPtr)
{
  int16_t value = encPtr->position;
  uint8_t i = 5;
  /*uint8_t f = 0;
  for(i; i <= 5; i++)
  {
    uint8_t k = digit(value, 6-i);
    if(k != 0 && f == 0)
		  f++;
		if(f != 0 || i == 5)
		{
		  PORTA = (1<<i);
		  PORTC = segments[k];
		}
  }
  */
  while((digit(value, i) == 0)&&(i > 1))
  {
    PORTC = 0;
    PORTA = (1 << (6-i));
    PORTA = 0;  

    i--;
  }

  if(value < 0)
  {
    PORTC = segments[10];
    PORTA = (1 << (5-i));
    PORTA = 0;
  }

  for(i; i >= 1; i--)
  {
    PORTC = segments[digit(value, i)];
    PORTA |= (1 << (6-i));
    PORTA &= ~(1 << (6-i));
  }
}
