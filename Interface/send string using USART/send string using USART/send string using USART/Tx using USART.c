#include "USART.h"
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
//transmitter
int main(void)
{
	UART_vinit(9600);
	_delay_ms(300);
	UART_vsendString("matarawy");
    while(1)
    {
         
    }
}