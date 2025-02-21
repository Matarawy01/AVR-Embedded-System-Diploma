/*
 * _7seg_driver.c
 *
 * Created: 10/8/2022 1:34:47 PM
 *  Author: abdel
 */ 
#define cc
#include "DIO_driver.h"
void seven_seg_vinit(unsigned char port)
{
	DIO_vset_portdir(port,0xff);
}
void seven_seg_write(unsigned char port,unsigned char number)
{
	#if defined cc
	char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
	#elif defined ca
	char arr[]={~0x3f,~0x06,~0x5b,~0x4f,~0x66,~0x6d,~0x7d,~0x47,~0x7f,~0x6f};
	#endif
	DIO_vwrite_port(port,arr[number]);	
}