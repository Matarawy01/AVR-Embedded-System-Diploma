#include"STD_TYPE.h"
#include  <util/delay.h>
#include "HLCD_Interface.h"


/************************************* 8 bit mode *****************************/

//function for sending command at 8bit mode all this code from data sheet
//send command make RS low
static void LCD_SendCommand(u8 command)
{
	MDIO_VoidSetPinValue(LCD_COTRL_PORT,RS,LOW);
	MDIO_VoidSetPortValue(LCD_DATA_PORT,command);
	MDIO_VoidSetPinValue(LCD_COTRL_PORT,EN,HIGH);
	_delay_ms(2);
	MDIO_VoidSetPinValue(LCD_COTRL_PORT,EN,LOW);
}
//function for sending Data at 8bit mode all this code from data sheet
//send data make RS high
static void LCD_SendData(u8 Data)
{
	MDIO_VoidSetPinValue(LCD_COTRL_PORT,RS,HIGH);
	MDIO_VoidSetPortValue(LCD_DATA_PORT,Data);
	MDIO_VoidSetPinValue(LCD_COTRL_PORT,EN,HIGH);
	_delay_ms(2);
	MDIO_VoidSetPinValue(LCD_COTRL_PORT,EN,LOW);
	_delay_ms(2);
}

//To init LCD at 8bit mode from datasheet
void LCD_VoidInit(void)
{

	MDIO_VoidSetPinDirection(LCD_COTRL_PORT, RS , OUTPUT);
	MDIO_VoidSetPinDirection(LCD_COTRL_PORT, EN , OUTPUT);
	MDIO_VoidSetPortDirection(LCD_DATA_PORT , ALL_OUTPUT);
	_delay_ms(50);
	LCD_SendCommand(FunctionSet);
	_delay_ms(1);
	LCD_SendCommand(DisplayOn);
	_delay_ms(1);
	LCD_SendCommand(DisplayClear);
	_delay_ms(2);
	LCD_SendCommand(EntryMode);
	_delay_ms(250);

}


//send char to data function to write the char on it
void LCD_VoidSendChar(u8 chr)
{
	LCD_SendData(chr);
}

//send string making array of char and send each char to SendData function until reach null
void LCD_VoidSendString(u8 *str)
{
	while((*str)!='\0')
	{
		_delay_ms(150);
		LCD_VoidSendChar(*str);
		str++;
	}
}


void LCD_VoidSendNumber(s32 Number)
{
	u8 arr[10];
	u8 j,i=0;

	if(Number == 0)
	{
		LCD_SendData('0');
	}

	if(Number < 0)
	{
		Number *= -1;
		LCD_SendData('-');
	}

	while(Number)
	{
		arr[i] = Number % 10 + '0';
		Number /= 10;
		i++;
	}

	for(j=i;j>0;j--)
	{
		LCD_SendData(arr[j-1]);
	}
}


void LCD_VoidClearScreen()
{
	LCD_SendCommand(0x01);
}


//first place = 0x80 (row=0,column=0)
//second line 1st place on it 64
//0xc0 = 0x80 + 0x40
void LCD_VoidCurserMove(ROW_Type line, u8 cell)
{
	if(cell <=15)
	{
		if(line == LINE1)
		{
			LCD_SendCommand(0x80 + cell);
		}
		else if(line == LINE2)
		{
			LCD_SendCommand(0xc0 + cell);
		}
	}
}


void LCD_VoidShiftRight(u8 num)
{
	int i;
	for(i=0;i<num;i++)
	{
		LCD_SendCommand(0x1c);
	}
}

void LCD_VoidSendBinary(u8 number)
{
	u8 i=0,j,BinaryNumber [10];
	if(number == 0)
	{
		LCD_SendData('0');
	}
	else
	{
		while(number > 0)
		{
			BinaryNumber[i] = number % 2 + '0';
			number = number / 2;
			i++;
		}
		for(j=i;j>0;j--)
		{
			LCD_SendData(BinaryNumber[j-1]);
		}
	}
}


void LCD_VoidSendHex(u8 number)
{
	u8 HexNum[10],i=0,j,Remain;
	if(number == 0)
	{
		LCD_SendData('0');
	}
	while(number>0)
	{
		Remain = number % 16;
		if(Remain < 10)
		{
			HexNum[i] = Remain + '0';
		}
		else
		{
			HexNum[i] = Remain -10 + 'A';
		}
		number /= 16;
		i++;
	}
	for(j=i;j>0;j--)
	{
		LCD_SendData(HexNum[j-1]);
	}

}
