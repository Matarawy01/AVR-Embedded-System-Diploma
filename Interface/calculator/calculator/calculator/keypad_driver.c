/*
 * keypad_driver.c
 *
 * Created: 12/13/2022 4:55:51 PM
 *  Author: abdel
 */ 
#include "lcd_driver.h"
#include "keypad_driver.h"
void keypad_vinit()
{
	DIO_vset_pindir('c',0,1);
	DIO_vset_pindir('c',1,1);
	DIO_vset_pindir('c',2,1);
	DIO_vset_pindir('c',3,1);
	DIO_vset_pindir('c',4,0);
	DIO_vset_pindir('c',5,0);
	DIO_vset_pindir('c',6,0);
	DIO_vset_pindir('c',7,0);
	DIO_vcontrolpullup('c',4,1);
	DIO_vcontrolpullup('c',5,1);
	DIO_vcontrolpullup('c',6,1);
	DIO_vcontrolpullup('c',7,1);
}
unsigned char keypad_u8read()
{
	unsigned char arr[4][4]={{'1','2','3','+'},{'4','5','6','-'},{'7','8','9','*'},{'.','0','=','/'}};
		char row,col,x;
		char returnval=0xff;
		for(row=0;row<4;row++)
		{
			DIO_vwrite_pin('c',0,1);
			DIO_vwrite_pin('c',1,1);
			DIO_vwrite_pin('c',2,1);
			DIO_vwrite_pin('c',3,1);
			DIO_vwrite_pin('c',row,0);
			
			for(col=0;col<4;col++)
			{
				x=DIO_U8read_pin('c',(col+4));
				if(x==0)
				{
					returnval=arr[row][col];
					break;
				}
			}
			if(x==0)
			{
				break;
			}
			
		}
		return returnval;
}