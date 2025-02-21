/*
 * keypad.c
 *
 * Created: 12/13/2022 4:55:22 PM
 *  Author: abdel
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include "lcd_driver.h"
#include "keypad_driver.h"
#include <util/delay.h>
int main(void)
{
	LCD_vinit();
	keypad_vinit();
	char x;
    while(1)
    {
        x=keypad_u8read();
		if(x!=0xff)
		{
			if(x=='.')
			{
				LCD_vsend_cmd(CLR_SCREEN);
			}
			else
			{
				LCD_vsend_char(x);
			}
			
		}
		_delay_ms(250);			
    }
}