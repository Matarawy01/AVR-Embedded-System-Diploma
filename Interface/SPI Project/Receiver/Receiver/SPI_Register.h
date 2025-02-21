/*
 * SPI_Register.h
 *
 * Created: 9/10/2023 2:17:50 PM
 *  Author: Abdelrahman Matarawy
 */ 


#ifndef SPI_REGISTER_H_
#define SPI_REGISTER_H_

#include "FUNC_LIKE_MACRO.h"
#include "STD_TYPE.h"

/* SPI Data Register */
#define SPDR    *((volatile u8*) 0x2F) 

/* SPI Status Register */
#define SPSR    *((volatile u8*) 0x2E)
#define SPIF    7 /* SPI Interrupt Flag */
#define WCOL    6 
#define SPI2X   0 /* Double SPI Speed Bit */

/* SPI Control Register */
#define SPCR    *((volatile u8*) 0x2D)
#define SPIE    7 /* SPI Interrupt Enable bit to access ISR */
#define SPE     6 /* SPI Enable bit To make SPI Enable */
#define DORD    5 /* Data Order bit To choose First Bit transmit LSB or MSB */
#define MSTR    4 /* Master/Slave Select bit to make MC as master or slave */
#define CPOL    3 /* Clock Polarity bit to choose if leading is raising or falling and trailing is raising or falling */
#define CPHA    2 /* Clock Polarity bit to choose ifsample is leading or trailing and setup is leading or trailing */
#define SPR1    1 /* to choose clk rate*/
#define SPR0    0   


#endif /* SPI_REGISTER_H_ */