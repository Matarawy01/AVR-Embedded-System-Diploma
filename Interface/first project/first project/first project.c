/*
 * first_project.c
 *
 * Created: 9/26/2022 6:57:12 AM
 *  Author: abdel
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "std_macros.h"
int main(void)
{
	SET_BIT(DDRA,2);
    while(1)
    {
        TOG_BIT(PORTA,2);
		_delay_ms(1000);
		
    }
}