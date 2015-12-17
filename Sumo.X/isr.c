#include "isr.h"
#include "macros.h"

extern unsigned char servo_set;
extern unsigned char servo_dir;
extern signed char servo_pos[8];


/*
* For PIC18cxxx devices the low interrupt vector is found at
* 00000018h. The following code will branch to the
* low_interrupt_service_routine function to handle
* interrupts that occur at the low vector.
*/

#pragma code low_vector = 0x18
void interrupt_at_low_vector(void)
{
	_asm GOTO low_isr _endasm
}
#pragma code /* return to the default code section */
#pragma interruptlow low_isr

void low_isr (void)
{

}

/*
* For PIC18cxxx devices the high interrupt vector is found at
* 00000008h. The following code will branch to the
* high_interrupt_service_routine function to handle
* interrupts that occur at the high vector.
*/

#pragma code high_vector = 0x08
void interrupt_at_high_vector(void)
{
	_asm GOTO high_isr _endasm
}
#pragma code /* return to the default code section */
#pragma interrupt high_isr

void high_isr (void)
{
	static unsigned char seq = 0;
	static unsigned char count = 0;

	PIR3bits.TMR4IF = 0;
	seq++;

	switch(seq)
	{
		case 1:
			TMR4 += 12;

			if(test_bit(servo_set, count))
			{
				switch(count)
				{
					case 0:
						OUT1 = 1;
						break;
					case 1:
						OUT2 = 1;
						break;
					case 2:
						OUT3 = 1;
						break;
					case 3:
						OUT4 = 1;
						break;
					case 4:
						OUT5 = 1;
						break;
					case 5:
						OUT6 = 1;
						break;
					case 6:
						OUT7 = 1;
						break;
					case 7:
						OUT8 = 1;
						break;
					default:
						break;
				}
			}
			break;

		case 2:			
			TMR4 = 0x80 - servo_pos[count];
		break;

		case 3:
			TMR4 = 0x80 + servo_pos[count];
			if(test_bit(servo_set, count))
			{
				switch(count)
					{
					case 0:
						OUT1 = 0;
						break;
					case 1:
						OUT2 = 0;
						break;
					case 2:
						OUT3 = 0;
						break;
					case 3:
						OUT4 = 0;
						break;
					case 4:
						OUT5 = 0;
						break;
					case 5:
						OUT6 = 0;
						break;
					case 6:
						OUT7 = 0;
						break;
					case 7:
						OUT8 = 0;
						break;
					default:
						break;
				}
			}
			
		break;

		case 4:
			TMR4 += 137;
			seq = 0;
			if(++count == 8)
				count = 0;
		break;

		default:
			break;
	}
}
