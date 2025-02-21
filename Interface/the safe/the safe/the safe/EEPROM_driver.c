/*
 * EEPROM_driver.c
 *
 * Created: 10/19/2022 3:02:13 PM
 *  Author: abdel
 */ 
#include "std_macros.h"
#include <avr/io.h>
void EEPROM_vwrite(unsigned short address,unsigned char data)
{
	EEAR=address;
	EEDR=data;
	SET_BIT(EECR,EEMWE);
	SET_BIT(EECR,EEWE);
	while(READ_BIT(EECR,EEWE)==1);
}
unsigned char EEPROM_u8read(unsigned short address)
{
	EEAR=address;
	SET_BIT(EECR,EERE);
	return EEDR;
}