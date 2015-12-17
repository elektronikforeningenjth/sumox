

#include "ad.h"




void adc_init(void)
{
	OpenADC(ADC_FOSC_8 & ADC_RIGHT_JUST & ADC_0_TAD, ADC_CH0 & ADC_INT_OFF & ADC_VREFPLUS_VDD & ADC_VREFMINUS_VSS, 0);
	Delay10TCYx(50);
}

unsigned int adc_read(unsigned char chan)
{
	unsigned int result;
	SetChanADC(chan);
	ConvertADC();         // Start conversion
	while(BusyADC());   // Wait for completion
	result = ReadADC();   // Read result
	//CloseADC();           // Disable A/D converter
	return result;
}