#ifndef __ISR_H__
#define __ISR_H__

#include <p18f8722.h>

#include "portmap.h"
#include "servo.h"

void low_isr(void);
void high_isr(void);

#endif //__ISR_H__


