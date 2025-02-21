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
void timer_1_wave_fastpwm_B(double value)
{
	SET_BIT(DDRD,5);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	OCR1B=value*1000;
	ICR1=19999;
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1A,COM1B1);
}
void timer_1_wave_fastpwm_A(double value)
{
	SET_BIT(DDRD,4);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);
	OCR1A=value*1000;
	ICR1=19999;
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1A,COM1A1);
}