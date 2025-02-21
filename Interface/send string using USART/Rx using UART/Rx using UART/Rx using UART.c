#include "lcd_driver.h"
#include "USART.h"
#include <avr/io.h>

int main(void)
{
	LCD_vinit();
	UART_vinit(9600);
	char x;
    while(1)
    {
        x=UART_u8ReceiveData();
		LCD_vsend_char(x);
    }
}