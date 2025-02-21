/*
 * EEPROM.c
 *
 * Created: 10/19/2022 12:33:41 PM
 *  Author: abdel
 */ 


#include <avr/io.h>
#include "EEPROM_driver.h"
int main(void)
{
	EEPROM_vwrite(0x0063,0x52);
    while(1)
    {
        
    }
}