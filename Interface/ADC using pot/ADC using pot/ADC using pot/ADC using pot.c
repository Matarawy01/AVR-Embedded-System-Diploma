/*
 * ADC_using_pot.c
 *
 * Created: 1/30/2023 12:52:59 PM
 *  Author: abdel
 */ 

#include "LED_driver.h"
#include <avr/io.h>
#include "ADC_driver.h"
int main(void)
{
	ADC_vinit();
	LED_vinit('d',0);
	LED_vinit('d',1);
	LED_vinit('d',2);
	LED_vinit('d',3);
	LED_vinit('d',4);
	LED_vinit('d',5);
	LED_vinit('d',6);
	LED_vinit('d',7);
    while(1)
    {
        PORTD=ADC_U16read();
    }
}