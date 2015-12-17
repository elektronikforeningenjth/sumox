
#ifndef __SERVO_H__
#define __SERVO_H__


void servo_inverted(unsigned char servo, unsigned char dir);
void servo_position(unsigned char servo, signed char pos);
void servo_enable(unsigned char servo, unsigned char enable);


#endif //__SERVO_H__