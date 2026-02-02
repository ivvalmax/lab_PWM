#include "../inc/common.h"

uint8_t digit(int16_t d, uint8_t m)
{
  uint8_t i = 1, a;
  if(d < 0)
  {
    d *= -1;
  }
  for(i; i <= m; i++)
  {
      a = d%10;
      d /= 10;
  }
  return(a);
}