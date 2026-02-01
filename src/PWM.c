
#include "../inc/PWM.h"

void PWMInit(void)
{
  TCCR3A = (1<<COM3A1)|(1<<COM3B1)|(1<<COM3C1)|(1<<WGM30);
  TCCR3B = (1<<WGM32) | (1<<CS31);
  OCR3AH = 0;
  OCR3AL = 0;
  OCR3BH = 0;
  OCR3BL = 0;
  OCR3CH = 0;
  OCR3CL = 0;
}

void PWMChange(Encoder_t* encPtr)
{
  uint8_t value = encPtr->position;

  OCR3AL = value;
  OCR3BL = 255-value;
  OCR3CL = 255-value;
}