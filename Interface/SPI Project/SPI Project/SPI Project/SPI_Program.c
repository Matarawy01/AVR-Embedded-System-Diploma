/*
 * SPI_Program.c
 *
 * Created: 9/10/2023 2:18:10 PM
 *  Author: Abdelrahman Matarawy
 */ 
#include "MDIO_Interface.h"
#include "SPI_Interface.h"
#include <util/delay.h>
void SPI_VoidMasterInit(void)
{
	/* Set SS as output to refer that's Master MC 
	* Set MOSI as output to refer that's Master MC
	  Set SCK as output to refer that's Master MC */ 
	MDIO_VoidSetPinDirection(PORT_B, PIN4, OUTPUT); 
	MDIO_VoidSetPinDirection(PORT_B, PIN5, OUTPUT);
	MDIO_VoidSetPinDirection(PORT_B, PIN7, OUTPUT); 
	/* Enable Master mode */
	Set_Bit(SPCR, MSTR);
	/* Enable SPI */
	Set_Bit(SPCR, SPE);
	#if ISR_State == With_ISR
	Set_Bit(SPCR, SPIE);
	#endif
	/* Set CLK to be Fsys/16 */
	Set_Bit(SPCR, SPR0);
	MDIO_VoidSetPinValue(PORT_B, PIN4, HIGH);
}

void SPI_VoidSlaveInit(void)
{
	/* Enable SPI */
	Set_Bit(SPCR, SPE);
	/* Set MISO as Output */
	MDIO_VoidSetPinDirection(PORT_B, PIN6, OUTPUT);
}

u8 SPI_U8MasterSendChar(u8 Data)
{
	/* Set SS as low to send data to slave */ 
	MDIO_VoidSetPinValue(PORT_B, PIN4, LOW);
	/* Put data in SPDR */
	SPDR = Data;
	/* Stop Until transmission Done */
	while(Read_Bit(SPSR, SPIF) == 0);
	/* Read SPDR */
	return SPDR;
}
/* In case I use ISR */
void SPI_MasterSendChar(u8 Data)
{
	/* Set SS as low to send data to slave */
	MDIO_VoidSetPinValue(PORT_B, PIN4, LOW);
	/* Put data in SPDR */
	SPDR = Data;
}

u8 SPI_U8SlaveReceiveChar(u8 Data)
{
	/* Set SS as low to send data to slave */
	MDIO_VoidSetPinValue(PORT_B, PIN4, LOW);
	/* Put data in SPDR */
	SPDR = Data;
	/* Stop Until transmission Done */
	while(Read_Bit(SPSR, SPIF) == 0);
	/* Read SPDR */
	return SPDR;
}

u8 SPI_U8MasterSendString(u8 *ptr)
{
	while((*ptr) != 0)
	{
		SPI_MasterSendChar(*ptr);
		ptr++;
		_delay_ms(300);
	}
}