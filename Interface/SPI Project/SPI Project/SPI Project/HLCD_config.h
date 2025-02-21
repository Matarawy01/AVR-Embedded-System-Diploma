/*
 * HLCD_config.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Abdelrahman Matarawy
 */

#ifndef HAL_LCD_HLCD_CONFIG_H_
#define HAL_LCD_HLCD_CONFIG_H_

#include "MDIO_Interface.h"

//set Register select(RS) at Pin 0 & set Enable at Pin 1
#define RS   PIN0
#define EN   PIN1







/************************************* 8 bit mode *****************************/
//Two rows of LCD defines
typedef enum{
	LINE1,
	LINE2
}ROW_Type;

//set all Pins in Port as output
#define  ALL_OUTPUT    0xFF
//set Data to write at port A & Contrl pins to write at port B
#define LCD_DATA_PORT  PORT_A
#define LCD_COTRL_PORT PORT_B

#define FunctionSet  0b00111000
#define DisplayOn	 0b00001110
#define DisplayOff	 0b00001010
#define DisplayClear 0b00000001
#define EntryMode    0b00000110

/*

#define D4  PORT_A,PIN4
#define D5  PORT_A,PIN5
#define D6  PORT_A,PIN6
#define D7  PORT_A,PIN7

#define LCD_COTRL_PORT PORT_B

#define FunctionSet  0b00101000
#define DisplayOn	 0b00001110
#define DisplayOff	 0b00001010
#define DisplayClear 0b00000001
#define EntryMode    0b00000110*/

#endif /* HAL_LCD_HLCD_CONFIG_H_ */
