/*
 * EVM.c
 *
 * Created: 12/14/2022 3:40:25 PM
 *  Author: abdel
 */ 
#include "lcd_driver.h"
#include "pushbutton_driver.h"
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
unsigned char counter1=0;
unsigned char counter2=0;
unsigned char counter3=0;
unsigned char counter4=0;
int main(void)
{
	LCD_vinit();
	pushbutton_vinit('b',3);
	pushbutton_vinit('b',4);
	pushbutton_vinit('b',5);
	pushbutton_vinit('b',6);
	pushbutton_vinit('b',7);
	
	LCD_vSend_string("A=0");
	LCD_vmove_cursor(1,12);
	LCD_vSend_string("B=0");
	LCD_vmove_cursor(2,1);
	LCD_vSend_string("C=0");
	LCD_vmove_cursor(2,12);
	LCD_vSend_string("D=0");
	
	while(1)
	{
		if(pushbutton_u8read('b',3)==1)
		{
			counter1++;
			LCD_vmove_cursor(1,3);
			if(counter1<10)
			{
				LCD_vsend_char(counter1+48);
			}
			else if(counter1<100)
			{
				LCD_vsend_char(counter1/10+48);
				LCD_vsend_char(counter1%10+48);
			}
			
		}
		else if(pushbutton_u8read('b',4)==1)
		{
			counter2++;
			LCD_vmove_cursor(1,14);
			LCD_vsend_char(counter2+48);
		}
		else if(pushbutton_u8read('b',5)==1)
		{
			counter3++;
			LCD_vmove_cursor(2,3);
			LCD_vsend_char(counter3+48);
		}
		else if(pushbutton_u8read('b',6)==1)
		{
			counter4++;
			LCD_vmove_cursor(2,14);
			LCD_vsend_char(counter4+48);
		}
		else if(pushbutton_u8read('b',7)==1)
		{
			counter1=counter2=counter3=counter4=0;
			LCD_vmove_cursor(1,1);
			LCD_vSend_string("A=0");
			LCD_vmove_cursor(1,12);
			LCD_vSend_string("B=0");
			LCD_vmove_cursor(2,1);
			LCD_vSend_string("C=0");
			LCD_vmove_cursor(2,12);
			LCD_vSend_string("D=0");
			LCD_vmove_cursor(1,1);
		}
		_delay_ms(200);
	}
}	
	
    