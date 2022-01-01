/*
 * DIO_GFC.h
 *
 * Created: 10/8/2021 10:42:06 PM
 *  Author: user
 */ 


#ifndef DIO_GFC_H_
#define DIO_GFC_H_

#include "DIO.h"

typedef struct{
	DIO_DirTypes PinDir;
	STD_LevelTypes Level;
	}DIO_PinCFG;

#define PINCOUNT 32


void DIO_Init(void);


#endif /* DIO_GFC_H_ */