/*
 * Relay.c
 *
 * Created: 10/18/2022 6:24:19 PM
 *  Author: abdel
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	DDRD=0x01;
    while(1)
    {
		PORTD = 0x0f;
		_delay_ms(1000);
        PORTD = 0x00;
        _delay_ms(1000);
    } 
}