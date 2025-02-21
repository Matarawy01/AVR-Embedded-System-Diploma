/*
 * control_pullup.c
 *
 * Created: 10/6/2022 11:04:45 AM
 *  Author: abdel
 */ 


#include <avr/io.h>
#include "DIO_driver.h"
#include "LED_driver.h"
#include "pushbutton_driver.h"
int main(void)
{
	char z;
	DIO_vcontrolpullup('a',0,1);
	pushbutton_vinit('a',0);
	LED_vinit('a',1);
    while(1)
    {
		z=pushbutton_u8read('a',0);
		if(z==0)
		{
			LED_von('a',1);
		}
		else
		{
			LED_voff('a',1);
		}						 
    }
}