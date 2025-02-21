#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LED_driver.h"
#include "pushbutton_driver.h"
#include "std_macros.h"
int main(void)
{
	LED_vinit('d',7);
	pushbutton_vinit('d',2);
	sei();
	
	GICR|=(1<<INT0);
	
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
	
    while(1)
    {
       LED_voff('d',7); 
    }
	 
}
ISR(INT0_vect)
{
	LED_von('d',7);
	_delay_ms(1000);
}