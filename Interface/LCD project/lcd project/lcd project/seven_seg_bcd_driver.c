/*
 * seven_seg_bcd_driver.c
 *
 * Created: 10/9/2022 10:08:12 PM
 *  Author: abdel
 */ 
#include "DIO_driver.h"
#include "std_macros.h"
void sevenseg_vinit_bcd(unsigned char port)
{
	DIO_vset_pindir(port,0,1);
	DIO_vset_pindir(port,1,1);
	DIO_vset_pindir(port,2,1);
	DIO_vset_pindir(port,3,1);
}
void sevenseg_vwrite_bcd(unsigned char port,unsigned char number)
{
	DIO_vwrite_pin(port,0,READ_BIT(number,0));
	DIO_vwrite_pin(port,1,READ_BIT(number,1));
	DIO_vwrite_pin(port,2,READ_BIT(number,2));
	DIO_vwrite_pin(port,3,READ_BIT(number,3));
}
