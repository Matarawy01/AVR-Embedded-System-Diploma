/*
 * LED_driver.h
 *
 * Created: 10/4/2022 8:02:19 PM
 *  Author: abdel
 */ 


#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_
void LED_vinit(unsigned char port,unsigned char pin);
void LED_von(unsigned char port,unsigned char pin);
void LED_voff(unsigned char port,unsigned char pin);
void LED_vtogg(unsigned char port,unsigned char pin);
char LED_u8readstatus(unsigned char port,unsigned char pin);
#endif /* LED_DRIVER_H_ */