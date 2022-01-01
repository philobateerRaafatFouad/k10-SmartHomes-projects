/*
* DIO.c
*
* Created: 10/8/2021 10:02:18 PM
*  Author: user
*/

#include "DIO.h"

void DIO_Write(DIO_ChannelTypes ChannelID,STD_LevelTypes Level){
	DIO_PortTypes Portx = ChannelID/8;
	DIO_ChannelTypes ChannelPos = ChannelID%8;
	switch(Portx){
		case DIO_PortA:
		if(Level == STD_High){
			SetBit(PORTA_Reg,ChannelPos);
		}
		else{
			ClearBit(PORTA_Reg,ChannelPos);
		}
		break;
		case DIO_PortB:
		if(Level == STD_High){
			SetBit(PORTB_Reg,ChannelPos);
		}
		else{
			ClearBit(PORTB_Reg,ChannelPos);
		}
		break;
		case DIO_PortC:
		if(Level == STD_High){
			SetBit(PORTC_Reg,ChannelPos);
		}
		else{
			ClearBit(PORTC_Reg,ChannelPos);
		}
		break;
		case DIO_PortD:
		if(Level == STD_High){
			SetBit(PORTD_Reg,ChannelPos);
		}
		else{
			ClearBit(PORTD_Reg,ChannelPos);
		}
		break;
	}
}
STD_LevelTypes DIO_Read(DIO_ChannelTypes ChannelID){
	STD_LevelTypes Level = STD_Low;
	DIO_PortTypes Portx = ChannelID/8;
	DIO_ChannelTypes ChannelPos = ChannelID%8;
	switch(Portx){
		case DIO_PortA:
		Level = GetBit(PINA_Reg,ChannelPos);
		break;
		case DIO_PortB:
		Level = GetBit(PINB_Reg,ChannelPos);
		break;
		case DIO_PortC:
		Level = GetBit(PINC_Reg,ChannelPos);
		break;
		case DIO_PortD:
		Level = GetBit(PIND_Reg,ChannelPos);
		break;
	}
	return Level;
}
void DIO_Toggle(DIO_ChannelTypes ChannelID){
	DIO_PortTypes Portx = ChannelID/8;
	DIO_ChannelTypes ChannelPos = ChannelID%8;
	switch(Portx){
		case DIO_PortA:
		ToggleBit(PORTA_Reg,ChannelPos);
		break;
		case DIO_PortB:
		ToggleBit(PORTB_Reg,ChannelPos);
		break;
		case DIO_PortC:
		ToggleBit(PORTC_Reg,ChannelPos);
		break;
		case DIO_PortD:
		ToggleBit(PORTD_Reg,ChannelPos);
		break;
	}
}