/*
 * CFile1.c
 *
 * Created: 1/30/2023 12:53:49 PM
 *  Author: abdel
 */ 
#include <avr/io.h>
#include "std_macros.h"
#define F_CPU 8000000UL
void ADC_vinit(void)
{
	SET_BIT(ADMUX,REFS0);
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADCSRA,ADEN);
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
	
}
unsigned short ADC_U16read(void)
{
	unsigned short read_val;
	SET_BIT(ADCSRA,ADSC);
	while(ADCSRA&(1<<ADSC)==1);
	read_val=(ADCL);
	read_val|=(ADCH<<8);
	return read_val;
}