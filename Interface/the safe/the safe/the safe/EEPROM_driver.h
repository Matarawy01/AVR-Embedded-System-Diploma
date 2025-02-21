/*
 * EEPROM_driver.h
 *
 * Created: 10/19/2022 3:02:29 PM
 *  Author: abdel
 */ 


#ifndef EEPROM_DRIVER_H_
#define EEPROM_DRIVER_H_

void EEPROM_vwrite(unsigned short adress,unsigned short data);
unsigned char EEPROM_u8read(unsigned short address);


#endif /* EEPROM_DRIVER_H_ */