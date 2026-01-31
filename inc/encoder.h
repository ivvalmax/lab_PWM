#ifndef ENCODER_H_
#define ENCODER_H_

#include "common.h"
typedef struct Encoder
{
  int16_t position;
  uint8_t resolution;
} Encoder_t;

void encoderInit(void);

#endif