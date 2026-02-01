#include "../inc/encoder.h"

Encoder_t encoder = {.position = 0, .resolution = 85};

void encoderInit(void)
{
  EICRA = (1 << ISC11)|(1 << ISC21);
  EIMSK = (1 << INT1)|(1 << INT2);
}

ISR (INT1_vect)
{
  if((PIND & (1 << 1)) != 0)
  {
    EICRA |= (1 << ISC10);
    if((PIND & (1 << 0)) != 0)
    {
      encoder.position += 255/encoder.resolution;
    }
    else
    {
      encoder.position -= 255/encoder.resolution;
    }
  }
  else
  {
    EICRA &= ~(1 << ISC10);
    if((PIND & (1 << 0)) != 0)
    {
      encoder.position -= 255/encoder.resolution;
    }
    else
    {
      encoder.position += 255/encoder.resolution;
    }      
  }
  encoder.position %= 255;
  
  OCR3AL = encoder.position;
  OCR3BL = 255-encoder.position;
  OCR3CL = 255-encoder.position;
  
}

ISR (INT2_vect)
{
  encoder.position = 0;
}