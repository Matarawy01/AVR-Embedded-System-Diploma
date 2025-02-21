/*
 * _7seg_project.c
 *
 * Created: 10/8/2022 12:35:28 PM
 *  Author: abdel
 */ 


#include <avr/io.h>
#include "seven_seg_driver.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	seven_seg_vinit('a');
	char i;
    while(1)
    {
        for(i=0;i<=9;i++)
		{
			seven_seg_write('a',i);
			_delay_ms(1000);
		}			
    }
}