/*
 * SPI_Project.c
 *
 * Created: 9/10/2023 3:24:57 PM
 *  Author: Abdelrahman Matarawy
 */ 


#include "SPI_Interface.h"
#include "HLCD_Interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	SPI_VoidSlaveInit();
	LCD_VoidInit();
	u8 x;
    while(1)
    {
       x=SPI_U8SlaveReceiveChar(x);
	   LCD_VoidSendChar(x);
    }
}