#ifndef SEVENSEGMENT_H_
#define SEVENSEGMENT_H_

#include "common.h"
#include "encoder.h"

void sevenSegmentInit(void);
void sevenSegmentClear(void);
void sevenSegmentWrite(Encoder_t *encPtr);

#endif