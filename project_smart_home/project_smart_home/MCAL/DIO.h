/*
 * DIO.h
 *
 * Created: 10/8/2021 9:49:20 PM
 *  Author: user
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "STD_Types.h"
#include "BitMath.h"
#include "DIO_HW.h"
#include "DIO_Types.h"
#include "DIO_GFC.h"

void DIO_Write(DIO_ChannelTypes ChannelID,STD_LevelTypes Level);
STD_LevelTypes DIO_Read(DIO_ChannelTypes ChannelID);
void DIO_Toggle(DIO_ChannelTypes ChannelID);

#endif /* DIO_H_ */