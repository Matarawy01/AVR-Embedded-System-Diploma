/*
 * DIO_project.c
 *
 * Created: 9/27/2022 9:49:45 AM
 *  Author: abdel
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "std_macros.h"
#include "DIO_driver.h"

int main(void)
{
	DIO_vset_portdir('a',0xff);
    while(1)
    {
		 DIO_vtoggle('a',0);
		 _delay_ms(100);
		 DIO_vtoggle('a',1);
		 _delay_ms(100);
		 DIO_vtoggle('a',2);
		 _delay_ms(100);
		  
    }
}