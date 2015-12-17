
#include "delay.h"


void delay_ms(long t)
{
	do
	{
		Delay1KTCYx(4);
	} while(--t);
}