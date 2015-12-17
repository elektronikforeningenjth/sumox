#ifndef __MACROS_H__
#define __MACROS_H__

#define test_bit(var, bit)		((var) & (1 << (bit)))
#define set_bit(var, bit)		((var) |= (1 << (bit)))
#define clr_bit(var, bit)		((var) &= ~(1 << (bit)))

#define btn_read()				((BTN4 << 3) | ( BTN3 << 2 ) | (BTN2 << 1 ) | BTN1)
#define bat_read()				(4 - BAT4 - BAT3 - BAT2 - BAT1)

#define servo_speed(servo, spd)	servo_pos((servo), (spd / 8))

#endif //__MACROS_H__
