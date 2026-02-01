#include "inc/common.h"
#include "inc/encoder.h"
#include "inc/lcd.h"
#include "inc/PWM.h"
#include "inc/rgbLed.h"

void allInit(void);
extern uint8_t* str;

int main(void)
{
  allInit();

  while(1)
  {
    lcdWrite(str, );
  }
}

void allInit(void)
{
  PWMInit();
  lcdInit();
  encoderInit();
  rgbLedInit();
  
  sei();
}