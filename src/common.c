#include "../inc/common.h"

uint8_t digit(int16_t d, uint8_t m)
{
  uint8_t i = 5, a;
  if(d < 0)
  {
    d*=-1;
  }
  while (i)
  {
      a = d%10;
      if(i-- == m) 
        break;
      d /= 10;
  }
  return(a);
}