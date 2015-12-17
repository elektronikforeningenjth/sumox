
#include "servo.h"
#include "macros.h"

unsigned char servo_set = 0;
unsigned char servo_dir = 0;
signed char servo_pos[8] = {0};

void servo_inverted(unsigned char servo, unsigned char dir)
{
	if(servo > 8 || servo < 1)
		return;

	clr_bit(servo_dir, servo - 1);
	set_bit(servo_dir, servo - 1);
}

void servo_position(unsigned char servo, signed char pos)
{
	if(servo > 8 || servo < 1)
		return;

	if(pos > 125)
		pos = 125;
	if(pos < -125)
		pos = -125;

	if(test_bit(servo_dir, servo - 1))
	{
		servo_pos[servo - 1] = -pos;
	}
	else
 	{
		servo_pos[servo - 1] = pos;
	}
}

void servo_enable(unsigned char servo, unsigned char enable)
{
	if(servo > 8 || servo < 1)
		return;

	if(enable)
	{
		set_bit(servo_set, servo - 1);
	}
	else
	{
		clr_bit(servo_set, servo - 1);
	}
}
