
#include "init.h"

void init(void)
{
	LED1_TRIS =		0;
	LED2_TRIS =		0;
	LED3_TRIS =		0;
	LED4_TRIS =		0;

	BTN1_TRIS =		1;
	BTN2_TRIS =		1;
	BTN3_TRIS =		1;
	BTN4_TRIS =		1;

	DIGI1_TRIS =	1;
	DIGI2_TRIS =	1;

	OUT1_TRIS =		0;
	OUT2_TRIS =		0;
	OUT3_TRIS =		0;
	OUT4_TRIS =		0;
	OUT5_TRIS =		0;
	OUT6_TRIS =		0;
	OUT7_TRIS =		0;

	IN1_TRIS =		1;
	IN2_TRIS =		1;
	IN3_TRIS =		1;
	IN4_TRIS =		1;
	IN5_TRIS =		1;
	IN6_TRIS =		1;
	IN7_TRIS =		1;
	IN8_TRIS =		1;

	SENS1_TRIS = 	1;
	SENS2_TRIS = 	1;
	SENS3_TRIS = 	1;
	SENS4_TRIS = 	1;
	SENS5_TRIS = 	1;
	SENS6_TRIS = 	1;
	SENS7_TRIS = 	1;
	SENS8_TRIS = 	1;

	SENSON_TRIS = 	0;

	LCD_RST_TRIS = 	0;
	LCD_RS_TRIS = 	0;
	LCD_CS_TRIS = 	0;
	LCD_SO_TRIS =	0;
	LCD_CLK_TRIS = 	0;

	LCD_BL1_TRIS =	0;
	LCD_BL2_TRIS =	0;

	SENSON_TRIS = 0;	

	LED1 = 0;
	LED2 = 0;
	LED3 = 0;
	LED4 = 0;

	OUT1 = 0;
	OUT2 = 0;
	OUT3 = 0;
	OUT4 = 0;
	OUT5 = 0;
	OUT6 = 0;
	OUT7 = 0;
	OUT8 = 0;

	LCD_RST = 0;

	LCD_BL1 = 0;
	LCD_BL2 = 0;
	
	SENSON = 1;

	OSCCONbits.IRCF2 = 1;
	OSCCONbits.IRCF1 = 1;
	OSCCONbits.IRCF0 = 0; //4MHz ...
	OSCTUNEbits.PLLEN = 1; //x 4 = 16MHz ^^


	RCONbits.IPEN = 1;		//enable interrupt priorities	
	T4CONbits.T4CKPS1 = 1;	//prescaler = 16
	T4CONbits.TMR4ON = 1;
	PIE3bits.TMR4IE = 1;
	INTCONbits.GIEH = 1;

}
