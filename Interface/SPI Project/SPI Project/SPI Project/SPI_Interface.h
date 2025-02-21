/*
 * SPI_Interface.h
 *
 * Created: 9/10/2023 2:17:34 PM
 *  Author: Abdelrahman Matarawy
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "SPI_Register.h"
#include "SPI_Config.h"

/* ISR State choose */
#define	With_ISR        1
#define WithOut_ISR     2


void SPI_VoidMasterInit(void);
void SPI_VoidSlaveInit(void);
u8 SPI_U8MasterSendChar(u8 Data);
void SPI_MasterSendChar(u8 Data);
u8 SPI_U8SlaveReceiveChar(u8 Data);
u8 SPI_U8MasterSendString(u8 *ptr);

#endif /* SPI_INTERFACE_H_ */