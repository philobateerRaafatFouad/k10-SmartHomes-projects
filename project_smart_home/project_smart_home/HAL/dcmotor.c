/*
* dcmotor.c
*
* Created: 12/6/2021 2:15:14 PM
*  Author: Kerolos
*/
#include "dcmotor.h"

void dcmotor_init(){
	DIO_Write(DIO_ChannelB5,STD_Low);
	DIO_Write(DIO_ChannelB6,STD_Low);

}
void dcmotor_rotate(dcmotor_state state ){
	if (state == dcmotor_cw)
	{
		DIO_Write(DIO_ChannelB5,STD_High);
		DIO_Write(DIO_ChannelB6,STD_Low);
	}
	else if (state == dcmotor_acw)
	{
		DIO_Write(DIO_ChannelB5,STD_Low);
		DIO_Write(DIO_ChannelB6,STD_High);
	}
	else if (state == dcmotor_stop)
	{
		DIO_Write(DIO_ChannelB5,STD_Low);
		DIO_Write(DIO_ChannelB6,STD_Low);
	}
}