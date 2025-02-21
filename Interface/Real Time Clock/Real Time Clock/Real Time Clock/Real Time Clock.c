#include <avr/io.h>
#include <avr/interrupt.h>
#include "lcd_driver.h";
#include "keypad_driver.h"
#include "seven_seg_driver.h"
#include "timer.h"
#include "std_macros.h"
#define F_CPU 8000000UL
#include <util/delay.h>
volatile unsigned char seconds_counter=0;
unsigned char minutes_counter=0,hours_counter=0;
unsigned char first_digit,second_digit,value;
int main(void)
{
	keypad_vinit();
	LCD_vinit();
	seven_seg_vinit('B');
	SET_BIT(DDRC,0);
	SET_BIT(DDRC,1);
	SET_BIT(DDRC,2);
	SET_BIT(DDRC,3);
	SET_BIT(DDRC,4);
	SET_BIT(DDRC,5);
	LCD_vSend_string("press 1 to");
	LCD_vmove_cursor(2,1);
	LCD_vSend_string("set clock");
	timer2_overflow_init_interrupt();
	
    while(1)
    {
		value=keypad_u8read();
		if(value!=NOTPASSED)
		{
			if(value =='1')
			{
				LCD_vclearscreen();
				LCD_vSend_string("hours=--");
				LCD_vmove_cursor(1,7);
				_delay_ms(500);
				do 
				{
					first_digit=keypad_u8read();
					
				} while (first_digit==NOTPASSED);
				LCD_vsend_char(first_digit);
				_delay_ms(300);
				do
				{
					second_digit=keypad_u8read();
					
				} while (second_digit==NOTPASSED);
				LCD_vsend_char(second_digit);
				_delay_ms(300);
				hours_counter=(first_digit-48)*10+(second_digit-48);
				LCD_vclearscreen();
				
				LCD_vSend_string("minutes=--");
				LCD_vmove_cursor(1,9);
				
				do
				{
					first_digit=keypad_u8read();
				} while (first_digit==NOTPASSED);
				LCD_vsend_char(first_digit);
				_delay_ms(300);
				do
				{
					second_digit=keypad_u8read();
				} while (second_digit==NOTPASSED);
				LCD_vsend_char(second_digit);
				_delay_ms(300);
				minutes_counter=(first_digit-48)*10+(second_digit-48);
				LCD_vclearscreen();
				
				LCD_vSend_string("seconds=--");
				LCD_vmove_cursor(1,9);
				
				do
				{
					first_digit=keypad_u8read();
				} while (first_digit==NOTPASSED);
				LCD_vsend_char(first_digit);
				_delay_ms(300);
				do
				{
					second_digit=keypad_u8read();
				} while (second_digit==NOTPASSED);
				LCD_vsend_char(second_digit);
				_delay_ms(300);
				seconds_counter=(first_digit-48)*10+(second_digit-48);
				LCD_vclearscreen();
				LCD_vSend_string("press 1 to");
				LCD_vmove_cursor(2,1);
				LCD_vSend_string("set clock");
			}
			else
			{
				LCD_vclearscreen();
				LCD_vSend_string("wrong choice");
				_delay_ms(1000);
				LCD_vclearscreen();
				LCD_vSend_string("press 1 to");
				LCD_vmove_cursor(2,1);
				LCD_vSend_string("set clock");
			}
		}
		
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,4);
		SET_BIT(PORTC,5);
		CLR_BIT(PORTC,0);
		seven_seg_write('B',seconds_counter%10);
		_delay_ms(5);
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,4);
		SET_BIT(PORTC,5);
		CLR_BIT(PORTC,1);	
		seven_seg_write('B',seconds_counter/10);
		_delay_ms(5);	
		
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,4);
		SET_BIT(PORTC,5);
		CLR_BIT(PORTC,2);
		seven_seg_write('b',minutes_counter%10);
		_delay_ms(5);
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,4);
		SET_BIT(PORTC,5);
		CLR_BIT(PORTC,3);
		seven_seg_write('b',minutes_counter/10);
		_delay_ms(5);
		
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,5);
		CLR_BIT(PORTC,4);
		seven_seg_write('B',hours_counter%10);
		_delay_ms(5);
		SET_BIT(PORTC,0);
		SET_BIT(PORTC,1);
		SET_BIT(PORTC,2);
		SET_BIT(PORTC,3);
		SET_BIT(PORTC,4);
		CLR_BIT(PORTC,5);
		seven_seg_write('B',hours_counter/10);
		_delay_ms(5);		
		
		if(seconds_counter==60)
		{
			seconds_counter=0;
			minutes_counter++;
		}
		if(minutes_counter==60)
		{
			minutes_counter=0;
			hours_counter++;
		}
		if(hours_counter==24)
		{
			hours_counter=0;
		}									
	}												
}
ISR(TIMER2_OVF_vect)
{
	seconds_counter++;
}