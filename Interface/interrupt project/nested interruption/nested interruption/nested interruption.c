#include <avr/interrupt.h>
#include <util/delay.h>
#define F_CPU 8000000UL
#include "LED_driver.h"
#include "std_macros.h"
#include <avr/io.h>

int main(void)
{
	
	LED_vinit('a',0);
	LED_vinit('a',1);
	LED_vinit('a',2);
	sei();
	
	SET_BIT(GICR,INT0);
	SET_BIT(GICR,INT1);
	SET_BIT(GICR,INT2);
	
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
	
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
	
	SET_BIT(MCUCSR,ISC2);
	
    while(1)
    {
		LED_voff('a',0);
		LED_voff('a',1);
		LED_voff('a',2);      
    }
}

ISR(INT0_vect)
{
	
	LED_von('a',0);
	_delay_ms(8000);	
	
}

ISR(INT1_vect)
{
	
	LED_von('a',1);
	_delay_ms(8000);
	
}

ISR(INT2_vect)
{
	
	LED_von('a',2);
	_delay_ms(8000);
	
}