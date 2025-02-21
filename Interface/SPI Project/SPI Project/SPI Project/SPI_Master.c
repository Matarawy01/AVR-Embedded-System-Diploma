/*
 * SPI_Project.c
 *
 * Created: 9/10/2023 3:24:57 PM
 *  Author: Abdelrahman Matarawy
 */ 


#include "SPI_Interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	SPI_VoidMasterInit();
	_delay_ms(500);
	SPI_U8MasterSendString("Matarawy");
}