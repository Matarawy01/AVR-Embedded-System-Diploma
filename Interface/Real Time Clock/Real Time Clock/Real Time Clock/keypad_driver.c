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
	DIO_vset_pindir('d',0,1);
	DIO_vset_pindir('d',1,1);
	DIO_vset_pindir('d',2,1);
	DIO_vset_pindir('d',3,1);
	DIO_vset_pindir('d',4,0);
	DIO_vset_pindir('d',5,0);
	DIO_vset_pindir('d',6,0);
	DIO_vset_pindir('d',7,0);
	DIO_vcontrolpullup('d',4,1);
	DIO_vcontrolpullup('d',5,1);
	DIO_vcontrolpullup('d',6,1);
	DIO_vcontrolpullup('d',7,1);
}
unsigned char keypad_u8read()
{
	unsigned char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'.','0','=','+'}};
		char row,col,x;
		char returnval=0xff;
		for(row=0;row<4;row++)
		{
			DIO_vwrite_pin('d',0,1);
			DIO_vwrite_pin('d',1,1);
			DIO_vwrite_pin('d',2,1);
			DIO_vwrite_pin('d',3,1);
			DIO_vwrite_pin('d',row,0);
			
			for(col=0;col<4;col++)
			{
				x=DIO_U8read_pin('d',(col+4));
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