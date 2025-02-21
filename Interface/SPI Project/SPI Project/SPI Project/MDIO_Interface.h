/* DIO_Interface
 *  Created on: Aug 22, 2023
 *      Author: Abdelrahman Matarawy
 */
#ifndef MDIO_H_
#define MDIO_H_

/******************************************** Calling Library used ****************************************/
#include "STD_TYPE.h"
#include "Func_Like_Macro.h"
#include "MDIO_Register.h"

#define ALL_OUTPUT 0xFF
//Enum for pins from 0 to 7
typedef enum{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
}DIO_Pin_Type;

//Enum for Ports
typedef enum{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
}DIO_Port_Type;

//Enum for Pin volt as high or low
typedef enum{
	LOW,
	HIGH
}DIO_PinVoltage_Type;

//Enum for pin as input or output
typedef enum{
	INPUT,
	OUTPUT
}DIO_PinStatus_Type;

/******************************************** Function Prototype ****************************************/
void MDIO_VoidSetPinDirection(DIO_Port_Type port, DIO_Pin_Type pin_num, DIO_PinStatus_Type direction);  //Set pin as input or output
void MDIO_VoidSetPinValue(DIO_Port_Type port, DIO_Pin_Type pin_num, DIO_PinVoltage_Type val);  //Set pin value as high or low
u8 MDIO_VoidReadPinValue(DIO_Port_Type port, DIO_Pin_Type pin_num);  //Read pin value
void MDIO_VoidSetPortDirection(DIO_Port_Type port, DIO_PinStatus_Type direction);  //Set port as input or output
void MDIO_VoidSetPortValue(DIO_Port_Type port, DIO_PinVoltage_Type val);  //Set port as high or low
void MDIO_VoidTogglePin(DIO_Port_Type port, DIO_Pin_Type pin_num); // toggle pin from high to low or vise verse

#endif
