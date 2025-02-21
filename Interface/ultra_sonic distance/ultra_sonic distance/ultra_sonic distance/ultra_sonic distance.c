#include <avr/io.h>
#include "lcd_driver.h"
#define F_CPU 1000000UL
#include <util/delay.h>
int main(void)
{
	LCD_vinit();
	unsigned short a,b,high,distance;
	DIO_vset_pindir('d',7,1);
    while(1)
    {
        TCCR1A=0;
		TIFR=(1<<ICF1);
		DIO_vwrite_pin('d',7,1);
		_delay_us(50);
		DIO_vwrite_pin('d',7,0);
		
		TCCR1B=0xc1;
		while((TIFR&(1<<ICF1))==0);
		a=ICR1;
		
		TIFR=(1<<ICF1);
		TCCR1B=0x81;
		while((TIFR&(1<<ICF1))==0);
		b=ICR1;
		
		TIFR=(1<<ICF1);
		TCNT1=0;
		TCCR1B=0;
		high=b-a;
		distance=((high*34600)/(2*F_CPU));
		if(distance>=80)
		{
			LCD_vclearscreen();
			LCD_vSend_string("No Object");
			_delay_ms(500);
		}
		else
		{
			LCD_vclearscreen();
			LCD_vSend_string("Distance = ");
			LCD_vsend_char((distance/10)+48);
			LCD_vsend_char((distance%10)+48);
			LCD_vSend_string("Cm");
			_delay_ms(500);
		}
	}								
}