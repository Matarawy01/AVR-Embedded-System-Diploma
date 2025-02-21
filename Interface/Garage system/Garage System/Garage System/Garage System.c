#include <avr/io.h>
#include "lcd_driver.h"
#define F_CPU 1000000UL
#include <util/delay.h>
#include "timer0.h"
int main(void)
{
	LCD_vinit();
	LCD_vSend_string("There are 0 cars");
	LCD_vmove_cursor(2,1);
	LCD_vSend_string("Garage has space");
	signed char flag1=0,flag2=0,IR1,IR2,counter=0;
    while(1)
    {
		IR1=DIO_U8read_pin('d',0);
		if(IR1==1 && flag1==0 && counter<3)
		{
			counter++;
			LCD_vmove_cursor(1,11);
			LCD_vsend_char(counter+48);
			flag1=1;
			if(counter==3)
			{
				LCD_vclearscreen();
				LCD_vSend_string("There are 3 cars");
				LCD_vmove_cursor(2,1);
				LCD_vSend_string("Garage is full");
			}
			timer_1_wave_fastpwm_B(1);
			_delay_ms(1000);
			timer_1_wave_fastpwm_B(1.5);
		}			
		else if(IR1==0)
		{
			flag1=0;
		}
		IR2=DIO_U8read_pin('d',1);
		if(IR2==1 && flag2==0 && counter>0)
		{
			counter--;
			LCD_vmove_cursor(1,11);
			LCD_vsend_char(counter+48);
			flag2=1;
			LCD_vclearscreen();
			LCD_vSend_string("there are ");
			LCD_vsend_char(counter+48);
			LCD_vSend_string(" cars");
			LCD_vmove_cursor(2,1);
			LCD_vSend_string("garage has space");
			timer_1_wave_fastpwm_A(1);
			_delay_ms(1000);
			timer_1_wave_fastpwm_A(1.5);
		}			
		else if(IR2==0)
		{
			flag2=0;
		}								
    }
}