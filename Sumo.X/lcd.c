

#include "lcd.h"

unsigned char LCD_Text[16];

void lcd_init(void)
{
	//Initierar SPI
	SSP1STATbits.SMP =		1; // Input data sampled at end of data output time
	SSP1STATbits.CKE =		0; // Transmit occurs on transition from Idle to active clock state
	
	SSP1CON1bits.SSPEN =	1; // Enables serial port and configures SCKx, SDOx, SDIx and SSx as serial port pins
	SSP1CON1bits.CKP =		1; // Idle state for clock is a high level
	SSP1CON1bits.SSPM0 =	0; // SPI Master mode, clock = FOSC/16

	LCD_CS = 1;

	LCD_RST = 1;	// Hardware reset of LCD
	delay_ms(40);

	lcd_cmd(0x39);	// 8bit length, 2lines, instruction table 1
	lcd_cmd(0x1D);	// BS: 1/4, 3 line LCD
	lcd_cmd(0x50);	// Booster off, contrast C5, set C4
	lcd_cmd(0x6C);	// Set voltage, follower and gain
	delay_ms(200);
	lcd_cmd(0x7B);	// Set contrast C3, C2, C1, C0
	lcd_cmd(0x38);	// Switch back to instruction table 0
	lcd_cmd(0x0C);	// Display on, cursor off
	lcd_cmd(0x01);	// Delete display, cursor at home
	delay_ms(2);
	lcd_cmd(0x06);	// Cursor auto-increment
}

void lcd_cmd(const unsigned char cmd)
{
	unsigned char i;

	LCD_RS = 0;

	PIR1bits.SSP1IF = 0;
	LCD_CS = 0;
	SSP1BUF = cmd;
	while(PIR1bits.SSP1IF != TRUE);
	LCD_CS = 1;
	Delay1KTCYx(2);
}

void lcd_txt(const unsigned char text[], unsigned char row)
{
	unsigned char i;
	lcd_cmd(LCD_DDRAM | row);

	LCD_RS = 1;

	for(i = 0; text[i] && (i < 16); i++)
	{
		PIR1bits.SSP1IF = 0;
		LCD_CS = 0;
		SSP1BUF = text[i];
		while(PIR1bits.SSP1IF != TRUE);
		LCD_CS = 1;
		Delay1KTCYx(2);
	}
}

void lcd_cls(void)
{
	lcd_cmd(0x01);	// Delete display, cursor at home
	Delay1KTCYx(2);
}

void lcd_contrast(unsigned char i)
{
	lcd_cmd(0x39);	// 8bit length, 2lines, instruction table 1
	lcd_cmd(0x70 | (i & 0x0F));	// Set contrast C3, C2, C1, C0
}

void lcd_brightness(unsigned char i)
{
	switch(i)
	{
		case 0:
			LCD_BL1 = 0;
			LCD_BL2 = 0;
			break;
		case 1:
			LCD_BL1 = 0;
			LCD_BL2 = 1;
			break;
		case 2:
			LCD_BL1 = 1;
			LCD_BL2 = 1;
			break;
		default:
			break;
	}	
}


