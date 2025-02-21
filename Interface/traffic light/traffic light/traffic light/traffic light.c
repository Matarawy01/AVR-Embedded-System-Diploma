/*
 * traffic_light.c
 *
 * Created: 2/15/2023 7:17:32 PM
 *  Author: abdel
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include "lcd_driver.h"
#include "LED_driver.h"
#include <util/delay.h>
volatile unsigned char counter=0;
unsigned char green = 10;
unsigned char yellow = 5;
unsigned char red = 7;
int main(void)
{
	LCD_vinit();
	timer_ctc_init_interrupt();
	LED_vinit('D',0);
	LED_vinit('D',1);
	LED_vinit('D',2);
	while(1)
	{
		green =10;
		yellow=5;
		red =7;
		LCD_vclearscreen();
		LCD_vSend_string("remaining 10 sec");
		LED_von('D',0);
		while(green>0)
		{
			if(counter>=100)
			{
				counter = 0;
				green--;
				LCD_vmove_cursor(1,11);
				LCD_vsend_char(' ');
				LCD_vsend_char(green + 48);
			}
		}
		LED_voff('D',0);
		LED_von('D',1);
		LCD_vclearscreen();
		LCD_vSend_string("remaining 5 sec");
		while(yellow>0)
		{
			if(counter>=100)
			{
				counter = 0;
				yellow--;
				LCD_vmove_cursor(1,11);
				LCD_vsend_char(yellow + 48);
			}
		}
		LED_voff('D',1);
		LED_von('D',2);
		LCD_vclearscreen();
		LCD_vSend_string("remaining 7 sec");
		while(red>0)
		{
			if(counter>=100)
			{
				counter = 0;
				red--;
				LCD_vmove_cursor(1,11);
				LCD_vsend_char(red + 48);
			}
		}
		LED_voff('D',2);
	}
}
ISR(TIMER0_COMP_vect)
{
	counter++;
}	