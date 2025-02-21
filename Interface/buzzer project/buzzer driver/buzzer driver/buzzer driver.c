/*
 * buzzer_driver.c
 *
 * Created: 10/5/2022 5:44:09 PM
 *  Author: abdel
 */ 


#include <avr/io.h>
#include "BUZZER_driver.h"
#define F_CPU 8000000UL
#include <util/delay.h>
int main(void)
{
	BUZZER_vinit('A',0);
    while(1)
    {
      BUZZER_von('a',0);
	  _delay_ms(1000);
	  BUZZER_voff('a',0);
	    
    }
}