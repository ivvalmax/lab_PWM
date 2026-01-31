#ifndef PWM_H_
#define PWM_H_

#include "common.h"
#include "encoder.h"

void PWMInit(void);
void PWMChange(Encoder_t* encPtr);

#endif