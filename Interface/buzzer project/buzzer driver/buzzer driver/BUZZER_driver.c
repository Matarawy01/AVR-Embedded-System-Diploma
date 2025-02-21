/*
 * CFile1.c
 *
 * Created: 10/5/2022 5:47:44 PM
 *  Author: abdel
 */ 
#include "DIO_driver.h"
void BUZZER_vinit(unsigned char port,unsigned char pin)
{
	DIO_vset_pindir(port,pin,1);
}
void BUZZER_von(unsigned char port,unsigned char pin)
{
	DIO_vwrite_pin(port,pin,1);
}
void BUZZER_voff(unsigned char port,unsigned char pin)
{
	DIO_vwrite_pin(port,pin,0);
}
void BUZZER_vtogg(unsigned char port,unsigned char pin)
{
	DIO_vtoggle(port,pin);
}
char BUZZER_u8readstatus(unsigned char port,unsigned char pin)
{
	return DIO_U8read_pin(port,pin);
}