#include <avr/io.h>
#include "lcd_driver.h"
#include "keypad_driver.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#define EEPROM_STATUS_LOCATION 0X20
#define EEPROM_PASSWORD_LOCATION1 0X21
#define EEPROM_PASSWORD_LOCATION2 0X22
#define EEPROM_PASSWORD_LOCATION3 0X23
#define EEPROM_PASSWORD_LOCATION4 0X24
#define MAX_TRIES 2
#define NOTPRESSED 0xff
char arr[4];
int main(void)
{
	char value=NOTPRESSED;
	char i,flag=0;
	char tries=MAX_TRIES;
	keypad_vinit();
	LCD_vinit();
	if(EEPROM_u8read(EEPROM_STATUS_LOCATION)==NOTPRESSED)
	{
		
		LCD_vSend_string("set pass:");
		for(i=0;i<4;i++)
		{
			do 
			{
				value=keypad_u8read();
			} while (value==NOTPRESSED);
			LCD_vsend_char(value);
			_delay_ms(500);
			LCD_vmove_cursor(1,10+i);
			LCD_vsend_char('*');
			EEPROM_vwrite(EEPROM_PASSWORD_LOCATION1+i,value);
		}
		EEPROM_vwrite(EEPROM_STATUS_LOCATION,0x00);
	}
	while(flag==0)
	{
		LCD_vclearscreen();
		LCD_vSend_string("check pass:");
		for(i=0;i<4;i++)
		{
			do
			{
				arr[i]=keypad_u8read();
			} while (arr[i]==NOTPRESSED);
			LCD_vsend_char(arr[i]);
			_delay_ms(500);
			LCD_vmove_cursor(1,12+i);
			LCD_vsend_char('*');
		}
		if(EEPROM_u8read(EEPROM_PASSWORD_LOCATION1)==arr[0] && EEPROM_u8read(EEPROM_PASSWORD_LOCATION2)==arr[1] && EEPROM_u8read(EEPROM_PASSWORD_LOCATION3)==arr[2] && EEPROM_u8read(EEPROM_PASSWORD_LOCATION4)==arr[3])
		{
			LCD_vclearscreen();
			LCD_vSend_string("Right password");
			LCD_vmove_cursor(2,1);
			LCD_vSend_string("safe opened");
			flag=1;
		}		
		else
		{
			tries--;
			if(tries>0)
			{
				LCD_vclearscreen();
				LCD_vSend_string("wrong password");
				_delay_ms(1000);
				LCD_vclearscreen();
				LCD_vSend_string("tries left");
				LCD_vsend_char(tries+48);
				_delay_ms(1000);
			}
			else
			{				
				LCD_vclearscreen();
				LCD_vSend_string("wrong password");
				_delay_ms(1000);
				LCD_vmove_cursor(2,1);
				LCD_vSend_string("safe closed");
				flag=1;
			}	
		}			
	}											
}