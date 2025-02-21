/*
 * LCD_Interface.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Abdelrahman Matarawy
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "HLCD_config.h"

void LCD_VoidInit(void);
void LCD_VoidSendChar(u8 chr);
void LCD_VoidClearScreen(void);
void LCD_VoidShiftRight(u8 num);
void LCD_VoidSendString(u8 *str);
void LCD_VoidSendNumber(s32 Number);
void LCD_VoidCurserMove(u8 line, u8 cell);
void LCD_VoidSendBinary(u8 number);
void LCD_VoidSendHex(u8 number);
#endif /* LCD_INTERFACE_H_ **/
