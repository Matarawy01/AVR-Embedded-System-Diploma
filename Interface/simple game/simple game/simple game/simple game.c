#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer0.h"
#include "lcd_driver.h"
#include "keypad_driver.h"
#define F_CPU 8000000UL
volatile int flag1=0,flag2=0;
int main(void)
{
	int x;
	LCD_vinit();
	keypad_vinit();
	LCD_vSend_string("3+?=8");
	timer_ctc_init_interrupt();
	do 
	{
		if(flag1>=1000)
		{
			flag2=1;
		}
		x=keypad_u8read();
	} while (x==NOTPASSED && flag2==0);
	if(x==NOTPASSED)
	{
		LCD_vclearscreen();
		LCD_vmove_cursor(2,4);
		LCD_vSend_string("TIME OVER");
	}
	else if(x=='5')
	{
		LCD_vclearscreen();
		LCD_vmove_cursor(2,4);
		LCD_vSend_string("WELL DONE");
	}
	else
	{
		LCD_vclearscreen();
		LCD_vmove_cursor(2,4);
		LCD_vSend_string("Wrong answer");
	}					
}
ISR(TIMER0_COMP_vect)
{
	flag1++;
}