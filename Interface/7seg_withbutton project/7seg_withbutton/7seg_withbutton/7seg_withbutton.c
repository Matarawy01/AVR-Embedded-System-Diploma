/*
 * _7seg_withbutton.c
 *
 * Created: 10/9/2022 9:03:48 PM
 *  Author: abdel
 */ 

#include "pushbutton_driver.h"
#include "seven_seg_driver.h"
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	pushbutton_vinit('b',0);
	seven_seg_vinit('a');
	char flag=0,z;
    while(1)
    {
		seven_seg_write('a',flag);
		z=pushbutton_u8read('b',0);
         if(z==1)
		 {
			 flag++;
		 }
		 if(flag>9)
		 {
			 flag=0;
		 }
		 _delay_ms(250);			 			 
    }
}