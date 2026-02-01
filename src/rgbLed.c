#include "../inc/rgbLed.h"

void rgbLedInit(void)
{
  DDRE = (1<<3) | (1<<4) | (1<<5);
}