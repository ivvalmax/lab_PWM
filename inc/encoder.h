#ifndef ENCODER_H_
#define ENCODER_H_

#include "common.h"
typedef struct Encoder
{
  uint8_t position;
  uint8_t resolution;
} Encoder_t;

void encoderInit(void);

#endif