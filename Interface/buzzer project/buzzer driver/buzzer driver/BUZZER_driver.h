/*
 * BUZZER_driver.h
 *
 * Created: 10/5/2022 5:48:39 PM
 *  Author: abdel
 */ 


#ifndef BUZZER_DRIVER_H_
#define BUZZER_DRIVER_H_
void BUZZER_vinit(unsigned char port,unsigned char pin);
void BUZZER_von(unsigned char port,unsigned char pin);
void BUZZER_voff(unsigned char port,unsigned char pin);
void BUZZER_vtogg(unsigned char port,unsigned char pin);
char BUZZER_u8readstatus(unsigned char port,unsigned char pin);
#endif /* BUZZER_DRIVER_H_ */