/*
 * Receiver.c
 *
 * Created: 9/10/2023 3:35:46 PM
 *  Author: abdel
 */ 

#include "SPI_Interface.h"
#include "HLCD_Interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	LCD_VoidInit();
	SPI_VoidSlaveInit();
	u8 x=0x30,z=0;
    while(z<10)
    {
		x= SPI_U8SlaveReceiveChar(x);
		LCD_VoidSendChar(x);
       z++;
    }
}