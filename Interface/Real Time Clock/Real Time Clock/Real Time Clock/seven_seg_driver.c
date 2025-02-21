#include "DIO_driver.h"
void seven_seg_vinit(unsigned char port)
{
	DIO_vset_portdir(port,0xff);
}

void seven_seg_write(unsigned char port,unsigned char number)
{
	
	char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};

	DIO_vwrite_port(port,arr[number]);	
}