/*
 * lcd_project.c
 *
 * Created: 11/29/2022 4:29:40 PM
 *  Author: abdel
 */ 



#define F_CPU 8000000UL
#include <util/delay.h>
#include "lcd_driver.h"
int main(void)
{
	LCD_vinit();
	LCD_vsend_cmd(64); LCD_vsend_char(0b00000000);//? ?? ???
 LCD_vsend_char(0b00000000);
 LCD_vsend_char(0b00000001);
 LCD_vsend_char(0b00000001);
 LCD_vsend_char(0b00011111);
 LCD_vsend_char(0b00000100);
 LCD_vsend_char(0b00000000);
 LCD_vsend_char(0b00000000);  LCD_vsend_char(0b00000000);//? ?? ???
 LCD_vsend_char(0b00000000);
 LCD_vsend_char(0b00000111);
 LCD_vsend_char(0b00000101);
 LCD_vsend_char(0b00000111);
 LCD_vsend_char(0b00000010);
 LCD_vsend_char(0b00000100);
 LCD_vsend_char(0b00000000);   LCD_vsend_char(0b00000000);//? ?? ???
 LCD_vsend_char(0b00000000);
 LCD_vsend_char(0b00000001);
 LCD_vsend_char(0b00000001);
 LCD_vsend_char(0b00011111);
 LCD_vsend_char(0b00000000);
 LCD_vsend_char(0b00000000);
 LCD_vsend_char(0b00000000);  LCD_vsend_char(0b00000000);//??? ?? ? LCD_vsend_char(0b00000000); LCD_vsend_char(0b00000011); LCD_vsend_char(0b00000100); LCD_vsend_char(0b00010100); LCD_vsend_char(0b00010010); LCD_vsend_char(0b00001100); LCD_vsend_char(0b00000000);  LCD_vsend_char(0b00000000);//? ?? ???
 LCD_vsend_char(0b00000000);
 LCD_vsend_char(0b00000100);
 LCD_vsend_char(0b00001010);
 LCD_vsend_char(0b00010001);
 LCD_vsend_char(0b00001001);
 LCD_vsend_char(0b00000110);
 LCD_vsend_char(0b00000000);  LCD_vsend_char(0b00000100);//??? ?? ? LCD_vsend_char(0b00000100); LCD_vsend_char(0b00000110); LCD_vsend_char(0b00001001); LCD_vsend_char(0b00011111); LCD_vsend_char(0b00000000); LCD_vsend_char(0b00000000); LCD_vsend_char(0b00000000);  LCD_vsend_char(0b00000000);//? ?? ???
 LCD_vsend_char(0b00000000);
 LCD_vsend_char(0b00000000);
 LCD_vsend_char(0b00000001);
 LCD_vsend_char(0b00000010);
 LCD_vsend_char(0b00000100);
 LCD_vsend_char(0b00001000);
 LCD_vsend_char(0b00000000); LCD_vsend_char(0b00000100);//? ?? ???
 LCD_vsend_char(0b00000100);
 LCD_vsend_char(0b00000100);
 LCD_vsend_char(0b00000100);
 LCD_vsend_char(0b00000100);
 LCD_vsend_char(0b00000000);
 LCD_vsend_char(0b00000000);
 LCD_vsend_char(0b00000000);    LCD_vmove_cursor(1,16); LCD_vsend_char(0); LCD_vmove_cursor(1,15); LCD_vsend_char(1); LCD_vmove_cursor(1,14); LCD_vsend_char(2); LCD_vmove_cursor(1,13); LCD_vsend_char(3); LCD_vmove_cursor(1,12); LCD_vsend_char(32); LCD_vmove_cursor(1,11); LCD_vsend_char(4); LCD_vmove_cursor(1,10); LCD_vsend_char(5); LCD_vmove_cursor(1,9); LCD_vsend_char(6); LCD_vmove_cursor(1,8); LCD_vsend_char(7);
 LCD_vmove_cursor(1,7); LCD_vsend_char(1);
 LCD_vmove_cursor(1,6); LCD_vsend_char(3);
 LCD_vmove_cursor(1,5);
    while(1)
    {
        
		
    }
}