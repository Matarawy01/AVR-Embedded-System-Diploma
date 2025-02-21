/*
 * first_try.c
 *
 * Created: 9/24/2022 6:44:44 PM
 *  Author: abdel
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	DDRA=0xff;
	char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f,0x77,0xf7,0x39,0x3f,0x79,0x71};
	int i;
    while(1)
    {
        for(i=0;i<=15;i++)
		{
			PORTA=arr[i];
			_delay_ms(1000);	
		}
		 
    }
}