
#ifndef	__AD_H__
#define	__AD_H__

#include <p18f8722.h>
#include <adc.h>
#include "delay.h"

void adc_init(void);
unsigned int adc_read(unsigned char chan);


#endif //__AD_H__


