/*
 * pushbutton_project.c
 *
 * Created: 10/6/2022 9:35:50 AM
 *  Author: abdel
 */ 


#include <avr/io.h>
#include "pushbutton_driver.h"
#include "LED_driver.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	char z;
	pushbutton_vinit('a',0);
	LED_vinit('a',1);
    while(1)
    {
     z=pushbutton_u8read('a',0);
	 if(z==1)
	 {
		LED_von('a',1); 
     }
	 else
	 {
		 LED_voff('a',1);
	 }
	}	 
}