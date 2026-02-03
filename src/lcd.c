#include "../inc/lcd.h"


uint8_t str[]={'R',':', ' ', '0', '0', '0',' ', 'G', ':', ' ','0','0','0', ' ', 'B', ':', ' ','0','0','0'};

void lcdCmd(uint8_t cmd)
{
  DDRC = 0xFF; // все разряды PORTC на выход
  DDRD |= ((1<<E)|(1<<RS));// разряды PORTD на выход
  PORTD &= ~(1<<RS);// выбор регистра команд RS=0
  PORTC = cmd; // записать команду в порт PORTC
  PORTD |= (1<<E); // \ сформировать на
  _delay_us(5); // | выводе E строб 1-0
  PORTD &= ~(1<<E); // / передачи команды
  _delay_ms(4);
}
void lcdInit(void)
{
  DDRC = 0xFF; // все разряды PORTC на выход
  DDRD |= ((1<<E)|(1<<RS)); // разряды PORTD на выход
  _delay_ms (100); // задержка для установления питания
  lcdCmd(0x30); // \ вывод
  lcdCmd(0x30); // | трех
  lcdCmd(0x30); // / команд 0x30
  lcdCmd(0x38); // 8 разр.шина, 2 строки, 5 × 7 точек
  lcdCmd(0x0C); // включить ЖКИ
  lcdCmd(0x06); // инкремент курсора, без сдвига экрана
  lcdCmd(0x01); // очистить экран, курсор в начало
}
void lcdData(uint8_t data)
{
  DDRC = 0xFF;
  DDRD |= ((1<<E)|(1<<RS));
  PORTD |= (1<<RS);
  PORTC = data;
  PORTD |= (1<<E);
  _delay_us(5);
  PORTD &= ~(1<<E);
  _delay_ms(4);
}

void lcdWrite(uint8_t r, uint8_t g, uint8_t b)
{
  uint8_t i = 0;
  
  for(uint8_t j = 3; j<=5; j++)
  {
    str[j] = digit(r, 6-j)+'0';
  }
  for(uint8_t j = 10; j<=12; j++)
  {
    str[j] = digit(r, 13-j)+'0';
  }
  for(uint8_t j = 17; j<=19; j++)
  {
    str[j] = digit(r, 20-j)+'0';
  }

  for(i = 0; i < sizeof(str); i++)
  {
    lcdData(str[i]);
    if(i == 13) lcdCmd((1 << 7)|(40));
  }

}
