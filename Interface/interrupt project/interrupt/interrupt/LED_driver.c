/*
 * LED_diver.c
 *
 * Created: 10/4/2022 8:01:53 PM
 *  Author: abdel
 */ 
#include "DIO_driver.h"
void LED_vinit(unsigned char port,unsigned char pin)
{
	DIO_vset_pindir(port,pin,1);
}
void LED_von(unsigned char port,unsigned char pin)
{
	DIO_vwrite_pin(port,pin,1);
}
void LED_voff(unsigned char port,unsigned char pin)
{
	DIO_vwrite_pin(port,pin,0);
}
void LED_vtogg(unsigned char port,unsigned char pin)
{
	DIO_vtoggle(port,pin);
}
char LED_u8readstatus(unsigned char port,unsigned char pin)
{
	return DIO_U8read_pin(port,pin);
}