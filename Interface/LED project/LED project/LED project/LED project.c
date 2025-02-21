/*
 * LED_project.c
 *
 * Created: 10/4/2022 8:00:37 PM
 *  Author: abdel
 */ 
#include "LED_driver.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>

int main(void)
{
	
    while(1)
    {
		int i;
       for(i=0;i<=7;i++)
	{LED_vinit('a',i);}
       for(i=0;i<=7;i++)
	   { 
		   LED_von('a',i);
		   _delay_ms(1000);
	   }	
	   for(i=7;i>=0;i--)
	   {
		   LED_voff('a',i);
		   _delay_ms(1000);
	   }
	   
    }
}