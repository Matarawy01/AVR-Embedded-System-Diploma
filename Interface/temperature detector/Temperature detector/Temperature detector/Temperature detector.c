/*
 * Temperature_detector.c
 *
 * Created: 2/3/2023 10:14:58 PM
 *  Author: abdel
 */ 


#include <avr/io.h>
#include "lcd_driver.h"
#include "ADC_driver.h"
#define F_CPU 8000000UL
unsigned short temperature;
char read_val;
int main(void)
{
	LCD_vinit();
	ADC_vinit();
	LED_vinit('B',7);//dio pin dir
	LCD_vSend_string("Temperature=");
    while(1)
    {
      temperature=(ADC_U16read()*0.25);
	  if(temperature>27)
	  {
		 LED_von('B',7);
		 /* if(temperature == 27)
		  {
			  DIO_vwrite_pin('B',7,1); 
		  }*/
	  }	
	  if(temperature<27)
	  {
		  LED_voff('B',7);
		 /* if(temperature == 27)
		  {
			  DIO_vwrite_pin('B',7,0);
		  }*/
	  }
	  
	  	  
	 if(temperature<10)
		  {
			  LCD_vmove_cursor(1,13);
			  LCD_vsend_char(temperature+48);
			  LCD_vsend_char(0xDF);
			  LCD_vsend_char('c');
			  LCD_vsend_char(0x20);
		  }
		  else if(temperature<100)
		  {
			 LCD_vmove_cursor(1,13);
			 LCD_vsend_char((temperature/10)+48);
			 LCD_vsend_char((temperature%10)+48);
			 LCD_vsend_char(0xDF);
			 LCD_vsend_char('c');
		  }
		  else
		  {}	
   }
} 