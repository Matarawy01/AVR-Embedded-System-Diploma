#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include "timer0.h"
#include "seven_seg_driver.h"
#include "std_macros.h"
volatile unsigned char counter1=0;
volatile unsigned char counter2=0;
volatile unsigned char counter3=0;
int main(void)
{
	seven_seg_vinit('d');
	timer_ctc_init_interrupt();
	SET_BIT(DDRA,0);
	SET_BIT(DDRA,1);
    while(1)
    {
		SET_BIT(PORTA,1);
		CLR_BIT(PORTA,0);
		seven_seg_write('d',counter2%10);
        while(counter3==0);
		counter3=0;
		CLR_BIT(PORTA,1);
		SET_BIT(PORTA,0);
		seven_seg_write('d',counter2/10);
		while(counter3==0);
		counter3=0;
		if(counter1>=100)
		{
			counter2++;
			counter1=0;
			if(counter2==100)
			{
				counter2=0;
			}
		}							
    }
}
ISR(TIMER0_COMP_vect)
{
	counter3=1;
	counter1++;
}