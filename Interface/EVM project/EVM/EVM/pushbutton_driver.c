/*
 * pushbutton_driver.c
 *
 * Created: 10/6/2022 9:36:26 AM
 *  Author: abdel
 */ 
#include "DIO_driver.h"
void pushbutton_vinit(unsigned char port,unsigned char pin)
{
	DIO_vset_pindir(port,pin,0);
}
unsigned char pushbutton_u8read(unsigned char port,unsigned char pin)
{
	unsigned char x;
	x=DIO_U8read_pin(port,pin);
	return x;
}