
#ifndef __LCD_H__
#define __LCD_H__

#include <p18f8722.h>
#include "portmap.h"
#include "delay.h"

#define	LCD_ROW1	0x00
#define	LCD_ROW2	0x10
#define	LCD_ROW3	0x20
#define LCD_DDRAM	0x80

#define FALSE		0U
#define TRUE		1U


void lcd_init(void);
void lcd_cmd(const unsigned char cmd);
void lcd_txt(const unsigned char text[], unsigned char row);
void lcd_cls(void);
void lcd_contrast(unsigned char i);
void lcd_brightness(unsigned char i);




#endif //__LCD_H__
