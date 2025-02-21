/*
 * timer0.c
 *
 * Created: 2/15/2023 6:50:27 AM
 *  Author: abdel
 */ 
#include "std_macros.h"
#include <avr/io.h>
#include <avr/interrupt.h>
void timer_ctc_init_interrupt(void)
{
	SET_BIT(TCCR0,WGM01);
	OCR0=80;
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	sei();
	SET_BIT(TIMSK,OCIE0);
}
void timer2_overflow_init_interrupt(void)
{
	SET_BIT(ASSR,AS2);
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS22);
	sei();
	SET_BIT(TIMSK,TOIE2);
}