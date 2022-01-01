/*
* DIO_GFC.c
*
* Created: 10/8/2021 10:47:28 PM
*  Author: user
*/

#include "DIO_GFC.h"

DIO_PinCFG PinCFG[] = {
	//PORTA
	{Input,STD_High},
	{Input,STD_High},
	{Input,STD_High},
	{Input,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	
	//PORTB
	{Input,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Input,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	//PORTC
	{Output,STD_High},
	{Input,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	//PORTD
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High}
};

void DIO_Init(){
	DIO_ChannelTypes count = 0;
	DIO_PortTypes Portx;
	DIO_ChannelTypes ChannelPos;
	for(count=DIO_ChannelA0;count<PINCOUNT;count++){
		Portx = count/8;
		ChannelPos = count%8;
		switch(Portx){
			case DIO_PortA:
			if(PinCFG[count].PinDir == Output){
				SetBit(DDRA_Reg,ChannelPos);
			}
			else
			{
				ClearBit(DDRA_Reg,ChannelPos);
			}
			break;
			case DIO_PortB:
			if(PinCFG[count].PinDir == Output){
				SetBit(DDRB_Reg,ChannelPos);
			}
			else
			{
				ClearBit(DDRB_Reg,ChannelPos);
			}
			break;
			case DIO_PortC:
			if(PinCFG[count].PinDir == Output){
				SetBit(DDRC_Reg,ChannelPos);
			}
			else
			{
				ClearBit(DDRC_Reg,ChannelPos);
			}
			break;
			case DIO_PortD:
			if(PinCFG[count].PinDir == Output){
				SetBit(DDRD_Reg,ChannelPos);
			}
			else
			{
				ClearBit(DDRD_Reg,ChannelPos);
			}
			break;
		}
	}

}