/*
 * toggle_leds_by_timer0.c
 *
 * Created: 2/15/2023 6:48:47 AM
 *  Author: abdel
 */ 


#include <avr/io.h>
#include "timer0.h"
#include "LED_driver.h"
#include <avr/interrupt.h>
unsigned char counter1=0;
unsigned char counter2=0;
unsigned short counter3=0;
int main(void)
{
	timer_ctc_init_interrupt();
	LED_vinit('B',0);
	LED_vinit('B',1);
	LED_vinit('B',2);
	while(1)
	{
		if(counter1 == 100)
		{
			LED_vtogg('B',0);
			counter1=0;
		}
		if(counter2 == 200)
		{
			LED_vtogg('B',1);
			counter2=0;	
		}
		if(counter3 == 300)
		{
			LED_vtogg('B',2);
			counter3=0;
		}
	}
	
}
ISR(TIMER0_COMP_vect)
{
	counter1++;
	counter2++;
	counter3++;
}