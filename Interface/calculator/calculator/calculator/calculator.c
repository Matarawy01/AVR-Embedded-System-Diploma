#include <avr/io.h>
#include "lcd_driver.h"
#include "keypad_driver.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	label: LCD_vinit();
	keypad_vinit();
	unsigned char arr[6]={0xff,0xff,0xff,0xff,0xff,0xff};
	unsigned short sign;
	unsigned char counter=0;
	while(1)
	{
		do 
		{
			arr[counter]=keypad_u8read();
		} while (arr[counter]==0xff);
		if(arr[counter]=='.'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
		{
			LCD_vclearscreen();
			goto label ;
		}
		else
		{
			LCD_vsend_char(arr[counter]);
		}
		counter++;
		_delay_ms(300);
		do
		{
			arr[counter]=keypad_u8read();
		} while (arr[counter]==0xff);
		if(arr[counter]=='.'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
		{
			LCD_vclearscreen();
			goto label ;
		}
		else
		{
			LCD_vsend_char(arr[counter]);
		}			
		counter++;
		_delay_ms(300);
		do
		{
			arr[counter]=keypad_u8read();
		} while (arr[counter]==0xff);
		if(arr[counter]=='.'||arr[counter]=='=')
		{
			LCD_vclearscreen();
			goto label ;
		}
		else
		{
			LCD_vsend_char(arr[counter]);
		}
		counter++;
		_delay_ms(300);
		do
		{
			arr[counter]=keypad_u8read();
		} while (arr[counter]==0xff);
		if(arr[counter]=='.'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
		{
			LCD_vclearscreen();
			goto label ;
		}
		else
		{
			LCD_vsend_char(arr[counter]);
		}
		counter++;
		_delay_ms(300);
		do
		{
			arr[counter]=keypad_u8read();
		} while (arr[counter]==0xff);
		if(arr[counter]=='.'||arr[counter]=='='||arr[counter]=='+'||arr[counter]=='-'||arr[counter]=='*'||arr[counter]=='/')
		{
			LCD_vclearscreen();
			goto label ;
		}
		else
		{
			LCD_vsend_char(arr[counter]);
		}
		counter++;
		_delay_ms(300);
		do
		{
			arr[counter]=keypad_u8read();
		} while (arr[counter]==0xff);
		if(arr[counter]=='=')
		{
			LCD_vsend_char(arr[counter]);
			switch(arr[counter-3])
			{
				case '+':
				sign=((arr[counter-4]-48)+((arr[counter-5]-48)*10))+(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
				if(sign>=100&&sign<1000)
				{
					LCD_vsend_char((sign/100)+48);
					LCD_vsend_char(((sign/10)%10)+48);
					LCD_vsend_char((sign%10)+48);
				}
				else if(sign>10&&sign<100)
				{
					LCD_vsend_char((sign/10)+48);
					LCD_vsend_char((sign%10)+48);
				}
				else if(sign<10)
				{
					LCD_vsend_char(sign+48);
				}
				break;
				case '-':
				sign=((arr[counter-4]-48)+((arr[counter-5]-48)*10))-(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
				if(sign>=100&&sign<1000)
				{
					LCD_vsend_char((sign/100)+48);
					LCD_vsend_char(((sign/10)%10)+48);
					LCD_vsend_char((sign%10)+48);
				}
				else if(sign>10&&sign<100)
				{
					LCD_vsend_char((sign/10)+48);
					LCD_vsend_char((sign%10)+48);
				}
				else if(sign<10)
				{
					LCD_vsend_char(sign+48);
				}
				break;
				case '*':
				sign=((arr[counter-4]-48)+((arr[counter-5]-48)*10))*(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
				if(sign>=1000&&sign<10000)
				{
					LCD_vsend_char((sign/1000)+48);
					LCD_vsend_char(((sign/100)%10)+48);
					LCD_vsend_char(((sign/10)%10)+48);
					LCD_vsend_char((sign%10)+48);
					
				}
				if(sign>=100&&sign<1000)
				{
					LCD_vsend_char((sign/100)+48);
					LCD_vsend_char(((sign/10)%10)+48);
					LCD_vsend_char((sign%10)+48);
				}
				else if(sign>10&&sign<100)
				{
					LCD_vsend_char((sign/10)+48);
					LCD_vsend_char((sign%10)+48);
				}
				else if(sign<10)
				{
					LCD_vsend_char(sign+48);
				}
				break;
				case '/':
				sign=((arr[counter-4]-48)+((arr[counter-5]-48)*10))/(((arr[counter-2]-48)*10)+(arr[counter-1]-48));
				if(sign>=100&&sign<1000)
				{
					LCD_vsend_char((sign/100)+48);
					LCD_vsend_char(((sign/10)%10)+48);
					LCD_vsend_char((sign%10)+48);
				}
				else if(sign>10&&sign<100)
				{
					LCD_vsend_char((sign/10)+48);
					LCD_vsend_char((sign%10)+48);
				}
				else if(sign<10)
				{
					LCD_vsend_char(sign+48);
				}
				break;
				default:break;
			}
		}
		else
		{
			LCD_vclearscreen();
			goto label ;
		}
		_delay_ms(200);
		}	
}	