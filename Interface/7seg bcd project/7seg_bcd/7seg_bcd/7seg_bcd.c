/*
 * _7seg_bcd.c
 *
 * Created: 10/9/2022 10:06:26 PM
 *  Author: abdel
 */ 

#include "seven_seg_bcd_driver.h"
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	sevenseg_vinit_bcd('a');
	char i;
    while(1)
    {
        for(i=0;i<=9;i++)
		{
			sevenseg_vwrite_bcd('a',i);
			_delay_ms(1000);
		}			
    }
}