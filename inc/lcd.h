#ifndef LCD_H_
#define LCD_H_

#include "common.h"
#include "encoder.h"


#define E 6
#define RS 7 


void lcdCmd(uint8_t cmd);
void lcdInit(void);
void lcdData(uint8_t data);
void lcdWrite(uint8_t* str, uint8_t r, uint8_t g, uint8_t b);

#endif