#include "inc/common.h"
#include "inc/encoder.h"
#include "inc/lcd.h"
#include "inc/PWM.h"
#include "inc/rgbLed.h"

void allInit(void);
extern uint8_t* str;
extern Encoder_t encoder;

int main(void)
{
  allInit();
  uint8_t r, g, b;
  while(1)
  {
    r = 255-encoder.position;
    g = encoder.position;
    b = r;
    lcdWrite(str, r, g, b);
    _delay_ms(50);
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