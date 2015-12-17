
#pragma config OSC = INTIO67, FCMEN = OFF, IESO = OFF, PWRT = OFF, BOREN = SBORDIS, BORV = 3, WDT = OFF
#pragma config WDTPS = 32768, MODE = MC, ADDRBW = ADDR20BIT, DATABW = DATA16BIT, WAIT = OFF, CCP2MX = PORTC
#pragma config ECCPMX = PORTE, LPT1OSC = OFF, MCLRE = ON, STVREN = ON, LVP = OFF, BBSIZ = BB2K, XINST = OFF

#include <p18f8722.h>
//#include <delays.h>
//#include <stdio.h>

//#include "macros.h"
//#include "portmap.h"
//#include "servo.h"
//#include "isr.h"
//#include "ad.h"
#include "lcd.h"
//#include "init.h"

#ifndef __PORTMAP_H__
#define __PORTMAP_H__
#include <adc.h>

#define BAT1			PORTHbits.RH0
#define BAT2			PORTHbits.RH1
#define BAT3			PORTHbits.RH2
#define BAT4			PORTHbits.RH3

#define LED1			PORTJbits.RJ4
#define LED2			PORTJbits.RJ5
#define LED3			PORTJbits.RJ6
#define LED4			PORTJbits.RJ7

#define BTN1			PORTDbits.RD1
#define BTN2			PORTDbits.RD0
#define BTN3			PORTAbits.RA7
#define BTN4			PORTJbits.RJ3

#define DIGI1			PORTBbits.RB4
#define DIGI2			PORTBbits.RB5

#define OUT1			PORTEbits.RE7
#define OUT2			PORTEbits.RE4
#define OUT3			PORTEbits.RE3
#define OUT4			PORTEbits.RE2
#define OUT5			PORTEbits.RE1
#define OUT6			PORTEbits.RE0
#define OUT7			PORTGbits.RG0
#define OUT8			PORTGbits.RG3

#define IN1				PORTHbits.RH4
#define IN2				PORTFbits.RF1
#define IN3				PORTFbits.RF0
#define IN4				PORTAbits.RA3
#define IN5				PORTAbits.RA2
#define IN6				PORTAbits.RA1
#define IN7				PORTAbits.RA0
#define IN8				PORTAbits.RA5

#define SENS1			PORTFbits.RF6
#define SENS2			PORTFbits.RF2
#define SENS3			PORTHbits.RH7
#define SENS4			PORTFbits.RF5
#define SENS5			PORTFbits.RF3
#define SENS6			PORTHbits.RH6
#define SENS7			PORTHbits.RH5
#define SENS8			PORTFbits.RF4

#define SENSON			PORTFbits.RF7

#define EXP1_1			PORTDbits.RD4
#define EXP1_2			PORTDbits.RD5
#define EXP1_3			PORTDbits.RD6
#define EXP1_4			PORTJbits.RJ2
#define EXP1_5			PORTBbits.RB0
#define EXP1_6			PORTBbits.RB1
#define EXP1_7			PORTBbits.RB2
#define EXP1_8			PORTBbits.RB3
#define EXP1_10			PORTAbits.RA6
#define EXP1_11			PORTCbits.RC5
#define EXP1_12			PORTCbits.RC4
#define EXP1_13			PORTCbits.RC3
#define EXP1_14			PORTCbits.RC2

#define EXP2_1			PORTEbits.RE6
#define EXP2_2			PORTEbits.RE5
#define EXP2_3			PORTGbits.RG1
#define EXP2_4			PORTGbits.RG2
#define EXP2_5			PORTGbits.RG4
#define EXP2_16			PORTAbits.RA4
#define EXP2_17			PORTCbits.RC1
#define EXP2_18			PORTCbits.RC0
#define EXP2_19			PORTCbits.RC6
#define EXP2_20			PORTCbits.RC7

#define LCD_RST			PORTDbits.RD7
#define LCD_RS			PORTJbits.RJ0
#define LCD_CS			PORTJbits.RJ1
#define LCD_SO			PORTCbits.RC5
#define LCD_CLK			PORTCbits.RC3

#define LCD_BL1			PORTDbits.RD2
#define LCD_BL2			PORTDbits.RD3

#define BAT1_TRIS		TRISHbits.TRISH0
#define BAT2_TRIS		TRISHbits.TRISH1
#define BAT3_TRIS		TRISHbits.TRISH2
#define BAT4_TRIS		TRISHbits.TRISH3

#define LED1_TRIS		TRISJbits.TRISJ4
#define LED2_TRIS		TRISJbits.TRISJ5
#define LED3_TRIS		TRISJbits.TRISJ6
#define LED4_TRIS		TRISJbits.TRISJ7

#define BTN1_TRIS		TRISDbits.TRISD1
#define BTN2_TRIS		TRISDbits.TRISD0
#define BTN3_TRIS		TRISAbits.TRISA7
#define BTN4_TRIS		TRISJbits.TRISJ3

#define DIGI1_TRIS		TRISBbits.TRISB4
#define DIGI2_TRIS		TRISBbits.TRISB5

#define OUT1_TRIS		TRISEbits.TRISE7
#define OUT2_TRIS		TRISEbits.TRISE4
#define OUT3_TRIS		TRISEbits.TRISE3
#define OUT4_TRIS		TRISEbits.TRISE2
#define OUT5_TRIS		TRISEbits.TRISE1
#define OUT6_TRIS		TRISEbits.TRISE0
#define OUT7_TRIS		TRISGbits.TRISG0
#define OUT8_TRIS		TRISGbits.TRISG3

#define IN1_TRIS		TRISHbits.TRISH4
#define IN2_TRIS		TRISFbits.TRISF1
#define IN3_TRIS		TRISFbits.TRISF0
#define IN4_TRIS		TRISAbits.TRISA3
#define IN5_TRIS		TRISAbits.TRISA2
#define IN6_TRIS		TRISAbits.TRISA1
#define IN7_TRIS		TRISAbits.TRISA0
#define IN8_TRIS		TRISAbits.TRISA5

#define SENS1_TRIS		TRISFbits.TRISF6
#define SENS2_TRIS		TRISFbits.TRISF2
#define SENS3_TRIS		TRISHbits.TRISH7
#define SENS4_TRIS		TRISFbits.TRISF5
#define SENS5_TRIS		TRISFbits.TRISF3
#define SENS6_TRIS		TRISHbits.TRISH6
#define SENS7_TRIS		TRISHbits.TRISH5
#define SENS8_TRIS		TRISFbits.TRISF4

#define SENSON_TRIS		TRISFbits.TRISF7

#define EXP1_1_TRIS		TRISDbits.TRISD4
#define EXP1_2_TRIS		TRISDbits.TRISD5
#define EXP1_3_TRIS		TRISDbits.TRISD6
#define EXP1_4_TRIS		TRISJbits.TRISJ2
#define EXP1_5_TRIS		TRISBbits.TRISB0
#define EXP1_6_TRIS		TRISBbits.TRISB1
#define EXP1_7_TRIS		TRISBbits.TRISB2
#define EXP1_8_TRIS		TRISBbits.TRISB3
#define EXP1_10_TRIS	TRISAbits.TRISA6
#define EXP1_11_TRIS	TRISCbits.TRISC5
#define EXP1_12_TRIS	TRISCbits.TRISC4
#define EXP1_13_TRIS	TRISCbits.TRISC3
#define EXP1_14_TRIS	TRISCbits.TRISC2

#define EXP2_1_TRIS		TRISEbits.TRISE6
#define EXP2_2_TRIS		TRISEbits.TRISE5
#define EXP2_3_TRIS		TRISGbits.TRISG1
#define EXP2_4_TRIS		TRISGbits.TRISG2
#define EXP2_5_TRIS		TRISGbits.TRISG4
#define EXP2_16_TRIS	TRISAbits.TRISA4
#define EXP2_17_TRIS	TRISCbits.TRISC1
#define EXP2_18_TRIS	TRISCbits.TRISC0
#define EXP2_19_TRIS	TRISCbits.TRISC6
#define EXP2_20_TRIS	TRISCbits.TRISC7

#define LCD_RST_TRIS	TRISDbits.TRISD7
#define LCD_RS_TRIS		TRISJbits.TRISJ0
#define LCD_CS_TRIS		TRISJbits.TRISJ1
#define LCD_SO_TRIS		TRISCbits.TRISC5
#define LCD_CLK_TRIS	TRISCbits.TRISC3

#define LCD_BL1_TRIS	TRISDbits.TRISD2
#define LCD_BL2_TRIS	TRISDbits.TRISD3

#define IN1_ADC			ADC_CH12
#define IN2_ADC			ADC_CH6
#define IN3_ADC			ADC_CH5
#define IN4_ADC			ADC_CH3
#define IN5_ADC			ADC_CH2
#define IN6_ADC			ADC_CH1
#define IN7_ADC			ADC_CH0
#define IN8_ADC			ADC_CH4

#define SENS1_ADC		ADC_CH11
#define SENS2_ADC		ADC_CH7
#define SENS3_ADC		ADC_CH15
#define SENS4_ADC		ADC_CH10
#define SENS5_ADC		ADC_CH8
#define SENS6_ADC		ADC_CH14
#define SENS7_ADC		ADC_CH13
#define SENS8_ADC		ADC_CH9

#endif //__PORTMAP_H__

extern unsigned char servo_set;
extern unsigned char servo_dir;
extern unsigned char LCD_Text[16];

void  init(void){
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

	//OSCCONbits.IRCF2 = 1;
	//OSCCONbits.IRCF1 = 1;
	//OSCCONbits.IRCF0 = 0; //4MHz ...
	//OSCTUNEbits.PLLEN = 1; //x 4 = 16MHz ^^


	//RCONbits.IPEN = 1;		//enable interrupt priorities
	//T4CONbits.T4CKPS1 = 1;	//prescaler = 16
	//T4CONbits.TMR4ON = 1;
	//PIE3bits.TMR4IE = 1;
	//INTCONbits.GIEH = 1;

}


void main(void)
{
    init();
    lcd_init();
    lcd_brightness(1);
    //void lcd_txt(const unsigned char text[], unsigned char row);

    const unsigned char text[3]={"HEJ"};
    unsigned char row = 1;
    //sprintf(LCD_Text, "Hello world!!!!!");
    lcd_cls();
    lcd_txt(text, row);

    //sprintf(LCD_Text, "Row 2           ");
    //lcd_txt(LCD_Text,LCD_ROW2);

    //sprintf(LCD_Text, "Row 3           ");
    //lcd_txt(LCD_Text,LCD_ROW3);
    //LED1 = 1;
    	LED1 = 0;
	LED2 = 0;
	LED3 = 0;
	LED4 = 1;
    while(1){
    //LED1 = 1;

      
    }
/*
	//Initializing
	init();
	lcd_init();
	adc_init();

	//set LCD brightness
	lcd_brightness(1);

	//set output 1,2 and 3 to servo output.
	//equal to
	//servo_enable(1,TRUE);
	//servo_enable(2,TRUE);
	//servo_enable(3,TRUE);
	servo_set = 0b00000111;

	//set servo 2 as inverted servo
	//equal to
	//servo_inverted(2, TRUE);
	servo_dir = 0b00000010;

	//Set servo position/speed to zero [range -125 to 125)
	servo_position(1,0);
	servo_position(2,0);


	//Write to LCD
	sprintf(LCD_Text, "Hello world!!!!!");
	lcd_txt(LCD_Text, LCD_ROW1);

	sprintf(LCD_Text, "Row 2           ");
	lcd_txt(LCD_Text,LCD_ROW2);

	sprintf(LCD_Text, "Row 3           ");
	lcd_txt(LCD_Text,LCD_ROW3);

	while(1)
	{
		if(BTN1)
		{
			servo_position(1, 100);
			LED1 = !LED1;
		}
		if(BTN2)
		{
			servo_position(1, -10);
			LED2 = !LED2;
		}
		if(BTN3)
		{
			servo_position(2, 100);
			LED3 = !LED3;
		}
		if(BTN4)
		{
			servo_position(2, -10);
			LED4 = !LED4;
		}
	}*/
}

