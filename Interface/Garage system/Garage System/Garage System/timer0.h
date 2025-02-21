/*
 * timer0.h
 *
 * Created: 2/15/2023 6:50:52 AM
 *  Author: abdel
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_
void timer_ctc_init_interrupt(void);


void timer_1_wave_fastpwm_A(double value);
void timer_1_wave_fastpwm_B(double value);

#endif /* TIMER0_H_ */