/* DIO_Program
 *  Created on: Aug 22, 2023
 *      Author: Abdelrahman Matarawy
 */
#include "MDIO_Interface.h"

/******************************************** Function Implementation ****************************************/
//function for set pin as output or input
void MDIO_VoidSetPinDirection(DIO_Port_Type port, DIO_Pin_Type pin_num, DIO_PinStatus_Type direction)
{
	if(direction == OUTPUT) //check if pin output or input
	{
		switch(port)
		{
		case PORT_A: Set_Bit(DDRA, pin_num);   break; //set pin in port A as output

		case PORT_B: Set_Bit(DDRB, pin_num);   break; //set pin in port B as output

		case PORT_C: Set_Bit(DDRC, pin_num);   break; //set pin in port C as output

		case PORT_D: Set_Bit(DDRD, pin_num);   break; //set pin in port D as output
		}
	}
	else
	{
		switch(port)
		{
		case PORT_A: Clear_Bit(DDRA, pin_num);  break; //set pin in port A as input

		case PORT_B: Clear_Bit(DDRB, pin_num);  break; //set pin in port B as input

		case PORT_C: Clear_Bit(DDRC, pin_num);  break; //set pin in port C as input

		case PORT_D: Clear_Bit(DDRD, pin_num);  break; //set pin in port D as input
		}
	}
}

//Function for set pin as high or low
void MDIO_VoidSetPinValue(DIO_Port_Type port, DIO_Pin_Type pin_num, DIO_PinVoltage_Type val)
{
	if(val == HIGH) //check if value is high or low
	{
		switch(port)
		{
		case PORT_A: Set_Bit(PORTA, pin_num);   break; //apply pin in port A as high

		case PORT_B: Set_Bit(PORTB, pin_num);   break; //apply pin in port B as high

		case PORT_C: Set_Bit(PORTC, pin_num);   break; //apply pin in port C as high

		case PORT_D: Set_Bit(PORTD, pin_num);   break; //apply pin in port D as high
		}
	}
	else
	{
		switch(port)
		{
		case PORT_A: Clear_Bit(PORTA, pin_num);  break; //apply pin in port A as low

		case PORT_B: Clear_Bit(PORTB, pin_num);  break; //apply pin in port B as low

		case PORT_C: Clear_Bit(PORTC, pin_num);  break; //apply pin in port C as low

		case PORT_D: Clear_Bit(PORTD, pin_num);  break; //apply pin in port D as low
		}
	}
}

//Function for read pin value
u8 MDIO_VoidReadPinValue(DIO_Port_Type port, DIO_Pin_Type pin_num)
{
	u8 value=0;
	switch(port)
	{
	case PORT_A: value = Read_Bit(PINA, pin_num);   break;

	case PORT_B: value = Read_Bit(PINB, pin_num);   break;

	case PORT_C: value = Read_Bit(PINC, pin_num);   break;

	case PORT_D: value = Read_Bit(PIND, pin_num);   break;
	}
	return value;
}

//function for set all pins in port as the input or output
void MDIO_VoidSetPortDirection(DIO_Port_Type port, DIO_PinStatus_Type direction)
{
	switch(port)
	{
	case PORT_A: DDRA =  direction;  break;

	case PORT_B: DDRB =  direction;  break;

	case PORT_C: DDRC =  direction;  break;

	case PORT_D: DDRD =  direction;  break;
	}
}

//function for set all pins in port as the value entered by user
void MDIO_VoidSetPortValue(DIO_Port_Type port, DIO_PinVoltage_Type val)
{
	switch(port)
	{
	case PORT_A: PORTA =  val;  break;

	case PORT_B: PORTB =  val;  break;

	case PORT_C: PORTC =  val;  break;

	case PORT_D: PORTD =  val;  break;
	}
}

//function to toggle pin in the port
void MDIO_VoidTogglePin(DIO_Port_Type port, DIO_Pin_Type pin_num)
{
	switch(port)
	{
	case PORT_A: Toggle_Bit(PORTA,pin_num); break;

	case PORT_B: Toggle_Bit(PORTB,pin_num); break;

	case PORT_C: Toggle_Bit(PORTC,pin_num); break;

	case PORT_D: Toggle_Bit(PORTD,pin_num); break;
	}
}
