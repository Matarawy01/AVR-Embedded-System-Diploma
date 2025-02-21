/*
 * seven_seg_bcd_driver.h
 *
 * Created: 10/9/2022 10:08:26 PM
 *  Author: abdel
 */ 


#ifndef SEVEN_SEG_BCD_DRIVER_H_
#define SEVEN_SEG_BCD_DRIVER_H_

void sevenseg_vinit_bcd(unsigned char port);
void sevenseg_vwrite_bcd(unsigned char port,unsigned char number);



#endif /* SEVEN_SEG_BCD_DRIVER_H_ */