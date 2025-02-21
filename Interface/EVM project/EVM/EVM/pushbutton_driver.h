/*
 * pushbutton_driver.h
 *
 * Created: 10/6/2022 9:36:48 AM
 *  Author: abdel
 */ 


#ifndef PUSHBUTTON_DRIVER_H_
#define PUSHBUTTON_DRIVER_H_
void pushbutton_vinit(unsigned char port,unsigned char pin);
unsigned char pushbutton_u8read(unsigned char port,unsigned char pin);



#endif /* PUSHBUTTON_DRIVER_H_ */